#include <iostream>
#include <fftw3.h>
int main(){
    int n = 10;
    fftw_complex *in, *out;
    fftw_plan p;

    in = (fftw_complex*) fftw_malloc(n*sizeof(fftw_complex));
    out = (fftw_complex*) fftw_malloc(n*sizeof(fftw_complex));
    p = fftw_plan_dft_1d(n, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p); /* repeat as needed */

    fftw_destroy_plan(p);

    fftw_free(in); fftw_free(out);

    return 0;
}