// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// downsample_run
Rcpp::IntegerVector downsample_run(Rcpp::IntegerVector reads, double prop);
RcppExport SEXP _DropletUtils_downsample_run(SEXP readsSEXP, SEXP propSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type reads(readsSEXP);
    Rcpp::traits::input_parameter< double >::type prop(propSEXP);
    rcpp_result_gen = Rcpp::wrap(downsample_run(reads, prop));
    return rcpp_result_gen;
END_RCPP
}
// downsample_run_per_cell
Rcpp::IntegerVector downsample_run_per_cell(Rcpp::IntegerVector cells, Rcpp::IntegerVector reads, Rcpp::NumericVector prop);
RcppExport SEXP _DropletUtils_downsample_run_per_cell(SEXP cellsSEXP, SEXP readsSEXP, SEXP propSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type cells(cellsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type reads(readsSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type prop(propSEXP);
    rcpp_result_gen = Rcpp::wrap(downsample_run_per_cell(cells, reads, prop));
    return rcpp_result_gen;
END_RCPP
}
// encode_sequences
Rcpp::IntegerVector encode_sequences(Rcpp::StringVector Seqs);
RcppExport SEXP _DropletUtils_encode_sequences(SEXP SeqsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type Seqs(SeqsSEXP);
    rcpp_result_gen = Rcpp::wrap(encode_sequences(Seqs));
    return rcpp_result_gen;
END_RCPP
}
// find_chimeric
Rcpp::List find_chimeric(Rcpp::StringVector cells, Rcpp::IntegerVector umis, Rcpp::IntegerVector reads, double minfrac, bool diagnostics);
RcppExport SEXP _DropletUtils_find_chimeric(SEXP cellsSEXP, SEXP umisSEXP, SEXP readsSEXP, SEXP minfracSEXP, SEXP diagnosticsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type cells(cellsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type umis(umisSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type reads(readsSEXP);
    Rcpp::traits::input_parameter< double >::type minfrac(minfracSEXP);
    Rcpp::traits::input_parameter< bool >::type diagnostics(diagnosticsSEXP);
    rcpp_result_gen = Rcpp::wrap(find_chimeric(cells, umis, reads, minfrac, diagnostics));
    return rcpp_result_gen;
END_RCPP
}
// find_swapped
Rcpp::List find_swapped(Rcpp::List cells, Rcpp::List genes, Rcpp::List umis, Rcpp::List reads, double minfrac, bool diagnostics);
RcppExport SEXP _DropletUtils_find_swapped(SEXP cellsSEXP, SEXP genesSEXP, SEXP umisSEXP, SEXP readsSEXP, SEXP minfracSEXP, SEXP diagnosticsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::List >::type cells(cellsSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type genes(genesSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type umis(umisSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type reads(readsSEXP);
    Rcpp::traits::input_parameter< double >::type minfrac(minfracSEXP);
    Rcpp::traits::input_parameter< bool >::type diagnostics(diagnosticsSEXP);
    rcpp_result_gen = Rcpp::wrap(find_swapped(cells, genes, umis, reads, minfrac, diagnostics));
    return rcpp_result_gen;
END_RCPP
}
// get_cell_barcodes
Rcpp::StringVector get_cell_barcodes(std::string fname, std::string dname, Rcpp::RObject barcodelen);
RcppExport SEXP _DropletUtils_get_cell_barcodes(SEXP fnameSEXP, SEXP dnameSEXP, SEXP barcodelenSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< std::string >::type fname(fnameSEXP);
    Rcpp::traits::input_parameter< std::string >::type dname(dnameSEXP);
    Rcpp::traits::input_parameter< Rcpp::RObject >::type barcodelen(barcodelenSEXP);
    rcpp_result_gen = Rcpp::wrap(get_cell_barcodes(fname, dname, barcodelen));
    return rcpp_result_gen;
END_RCPP
}
// group_cells
Rcpp::List group_cells(Rcpp::StringVector cells, Rcpp::IntegerVector gems);
RcppExport SEXP _DropletUtils_group_cells(SEXP cellsSEXP, SEXP gemsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::StringVector >::type cells(cellsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type gems(gemsSEXP);
    rcpp_result_gen = Rcpp::wrap(group_cells(cells, gems));
    return rcpp_result_gen;
END_RCPP
}
// hashed_deltas
Rcpp::List hashed_deltas(Rcpp::RObject mat, Rcpp::NumericVector prop, double pseudo_count);
RcppExport SEXP _DropletUtils_hashed_deltas(SEXP matSEXP, SEXP propSEXP, SEXP pseudo_countSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::RObject >::type mat(matSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type prop(propSEXP);
    Rcpp::traits::input_parameter< double >::type pseudo_count(pseudo_countSEXP);
    rcpp_result_gen = Rcpp::wrap(hashed_deltas(mat, prop, pseudo_count));
    return rcpp_result_gen;
END_RCPP
}
// montecarlo_pval
Rcpp::IntegerVector montecarlo_pval(Rcpp::IntegerVector totalval, Rcpp::IntegerVector totallen, Rcpp::NumericVector prob, Rcpp::NumericVector ambient, int iterations, double alpha, Rcpp::List seeds, Rcpp::IntegerVector streams);
RcppExport SEXP _DropletUtils_montecarlo_pval(SEXP totalvalSEXP, SEXP totallenSEXP, SEXP probSEXP, SEXP ambientSEXP, SEXP iterationsSEXP, SEXP alphaSEXP, SEXP seedsSEXP, SEXP streamsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type totalval(totalvalSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type totallen(totallenSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type prob(probSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type ambient(ambientSEXP);
    Rcpp::traits::input_parameter< int >::type iterations(iterationsSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type seeds(seedsSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type streams(streamsSEXP);
    rcpp_result_gen = Rcpp::wrap(montecarlo_pval(totalval, totallen, prob, ambient, iterations, alpha, seeds, streams));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_DropletUtils_downsample_run", (DL_FUNC) &_DropletUtils_downsample_run, 2},
    {"_DropletUtils_downsample_run_per_cell", (DL_FUNC) &_DropletUtils_downsample_run_per_cell, 3},
    {"_DropletUtils_encode_sequences", (DL_FUNC) &_DropletUtils_encode_sequences, 1},
    {"_DropletUtils_find_chimeric", (DL_FUNC) &_DropletUtils_find_chimeric, 5},
    {"_DropletUtils_find_swapped", (DL_FUNC) &_DropletUtils_find_swapped, 6},
    {"_DropletUtils_get_cell_barcodes", (DL_FUNC) &_DropletUtils_get_cell_barcodes, 3},
    {"_DropletUtils_group_cells", (DL_FUNC) &_DropletUtils_group_cells, 2},
    {"_DropletUtils_hashed_deltas", (DL_FUNC) &_DropletUtils_hashed_deltas, 3},
    {"_DropletUtils_montecarlo_pval", (DL_FUNC) &_DropletUtils_montecarlo_pval, 8},
    {NULL, NULL, 0}
};

RcppExport void R_init_DropletUtils(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
