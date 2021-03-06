# This tests that calcaultion of statistics works correctly.
# library(DropletUtils); library(testthat); source("test-molstats.R")

tmpdir <- tempfile(fileext=".h5")
ngenes <- 20L
barcode <- 4L

REFFUN <- function(cells, gems) {
    out <- sprintf("%s-%i", cells, gems)
    o <- order(out)
    rout <- rle(out[o])
    id <- rep(seq_along(rout$value), rout$length)
    list(order=o, id=id,
        cell=sub("-.*", "", rout$value),
        gem=as.integer(sub(".*-", "", rout$value)),
        length=rout$length)
}

set.seed(909)
test_that("Combined cell/gem reordering works correctly", {
    output <- DropletUtils:::simBasicMolInfo(tmpdir, barcode=barcode)
    raw <- read10xMolInfo(output)
    expect_identical(DropletUtils:::.get_cell_ordering(raw$data$cell, raw$data$gem_group), 
            REFFUN(raw$data$cell, raw$data$gem_group))

    # Multiple GEM groups (REFFUN doesn't work with double-digits properly, hence '9').
    raw$data$gem_group <- sample(9, nrow(raw$data), replace=TRUE)
    expect_identical(DropletUtils:::.get_cell_ordering(raw$data$cell, raw$data$gem_group), 
            REFFUN(raw$data$cell, raw$data$gem_group))

    # Sparser data.
    output <- DropletUtils:::simBasicMolInfo(tmpdir, barcode=barcode, nmolecules=500)
    raw <- read10xMolInfo(output)
    expect_identical(DropletUtils:::.get_cell_ordering(raw$data$cell, raw$data$gem_group), 
            REFFUN(raw$data$cell, raw$data$gem_group))

    # Handles silly inputs.
    test <- DropletUtils:::.get_cell_ordering(character(0), integer(0))
    expect_true(all(lengths(test)==0))
    expect_error(DropletUtils:::.get_cell_ordering(character(0), 1L), "should be the same length")
})

set.seed(909)
test_that("Calculation of statistics is correct", {
    output <- DropletUtils:::simBasicMolInfo(tmpdir, barcode=barcode)
    stats <- get10xMolInfoStats(output)
    expect_identical(order(stats$cell, stats$gem_group), seq_len(nrow(stats)))

    raw <- read10xMolInfo(output)
    raw.groups <- REFFUN(raw$data$cell, raw$data$gem_group)
    expect_identical(stats$num.umis, raw.groups$length)

    ref <- vapply(split(raw$data$reads[raw.groups$order], raw.groups$id), FUN=sum, FUN.VALUE=0L, USE.NAMES=FALSE)
    expect_identical(stats$num.reads, ref)

    ref <- vapply(split(raw$data$gene[raw.groups$order], raw.groups$id), 
        FUN=function(x) length(unique(x)), FUN.VALUE=0L, USE.NAMES=FALSE)
    expect_identical(stats$num.genes, ref)

    # Sparser data.
    output <- DropletUtils:::simBasicMolInfo(tmpdir, barcode=barcode, nmolecules=500)
    stats <- get10xMolInfoStats(output)
    expect_identical(order(stats$cell, stats$gem_group), seq_len(nrow(stats)))

    raw <- read10xMolInfo(output)
    raw.groups <- REFFUN(raw$data$cell, raw$data$gem_group)
    expect_identical(stats$num.umis, raw.groups$length)

    ref <- vapply(split(raw$data$reads[raw.groups$order], raw.groups$id), FUN=sum, FUN.VALUE=1L, USE.NAMES=FALSE)
    expect_identical(stats$num.reads, ref)

    ref <- vapply(split(raw$data$gene[raw.groups$order], raw.groups$id), 
        FUN=function(x) length(unique(x)), FUN.VALUE=1L, USE.NAMES=FALSE)
    expect_identical(stats$num.genes, ref)

    # Behaves when there are no molecules.
    empty <- DropletUtils:::simBasicMolInfo(tmpdir, barcode=barcode, nmolecules=0)
    stats <- get10xMolInfoStats(empty)
    expect_identical(nrow(stats), 0L)
})

test_that("chimericDrops respects the use.library= restriction", {
    tmpdir <- tempfile(fileext=".h5")
    fname <- DropletUtils:::simBasicMolInfo(tmpdir, version="3")

    # Behaves properly when no restriction is placed down.
    ref <- get10xMolInfoStats(fname)
    expect_true(nrow(ref) > 0L)

    ref2 <- get10xMolInfoStats(fname, use.library=1:3)
    expect_identical(ref, ref2)

    # Correctly empties out when a restriction is applied.
    output <- get10xMolInfoStats(fname, use.library="XXX")
    expect_identical(nrow(output), 0L)

    output <- get10xMolInfoStats(fname, use.library="A")
    expect_true(nrow(output) > 0L)
})
