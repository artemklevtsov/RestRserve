// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// escape_chars
std::string escape_chars(const std::string& x);
RcppExport SEXP _RestRserve_escape_chars(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(escape_chars(x));
    return rcpp_result_gen;
END_RCPP
}
// deparse_vector
Rcpp::CharacterVector deparse_vector(Rcpp::CharacterVector x);
RcppExport SEXP _RestRserve_deparse_vector(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(deparse_vector(x));
    return rcpp_result_gen;
END_RCPP
}
// format_headers
Rcpp::CharacterVector format_headers(Rcpp::ListOf<Rcpp::CharacterVector> x);
RcppExport SEXP _RestRserve_format_headers(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::ListOf<Rcpp::CharacterVector> >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(format_headers(x));
    return rcpp_result_gen;
END_RCPP
}
// parse_cookies
Rcpp::List parse_cookies(const std::vector<std::string>& x);
RcppExport SEXP _RestRserve_parse_cookies(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(parse_cookies(x));
    return rcpp_result_gen;
END_RCPP
}
// parse_headers
Rcpp::List parse_headers(const std::string& headers);
RcppExport SEXP _RestRserve_parse_headers(SEXP headersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type headers(headersSEXP);
    rcpp_result_gen = Rcpp::wrap(parse_headers(headers));
    return rcpp_result_gen;
END_RCPP
}
// url_decode_one
std::string url_decode_one(const std::string& value);
RcppExport SEXP _RestRserve_url_decode_one(SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type value(valueSEXP);
    rcpp_result_gen = Rcpp::wrap(url_decode_one(value));
    return rcpp_result_gen;
END_RCPP
}
// url_decode
Rcpp::CharacterVector url_decode(Rcpp::CharacterVector x);
RcppExport SEXP _RestRserve_url_decode(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(url_decode(x));
    return rcpp_result_gen;
END_RCPP
}
// url_encode_one
std::string url_encode_one(const std::string& value);
RcppExport SEXP _RestRserve_url_encode_one(SEXP valueSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type value(valueSEXP);
    rcpp_result_gen = Rcpp::wrap(url_encode_one(value));
    return rcpp_result_gen;
END_RCPP
}
// url_encode
Rcpp::CharacterVector url_encode(Rcpp::CharacterVector x);
RcppExport SEXP _RestRserve_url_encode(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::CharacterVector >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(url_encode(x));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RestRserve_escape_chars", (DL_FUNC) &_RestRserve_escape_chars, 1},
    {"_RestRserve_deparse_vector", (DL_FUNC) &_RestRserve_deparse_vector, 1},
    {"_RestRserve_format_headers", (DL_FUNC) &_RestRserve_format_headers, 1},
    {"_RestRserve_parse_cookies", (DL_FUNC) &_RestRserve_parse_cookies, 1},
    {"_RestRserve_parse_headers", (DL_FUNC) &_RestRserve_parse_headers, 1},
    {"_RestRserve_url_decode_one", (DL_FUNC) &_RestRserve_url_decode_one, 1},
    {"_RestRserve_url_decode", (DL_FUNC) &_RestRserve_url_decode, 1},
    {"_RestRserve_url_encode_one", (DL_FUNC) &_RestRserve_url_encode_one, 1},
    {"_RestRserve_url_encode", (DL_FUNC) &_RestRserve_url_encode, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_RestRserve(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
