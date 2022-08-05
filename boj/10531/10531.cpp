#include <bits/stdc++.h>
using namespace std;
void fast_io() {
  cin.tie(0)->sync_with_stdio(0);
}
bool chk[200001];
const double PI = acos(-1);
typedef complex<double> cpx;
void FFT(vector<cpx> &v, bool inv) {
    int S = v.size();

    for(int i=1, j=0; i<S; i++) {
        int bit = S/2;

        while(j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;

        if(i < j) swap(v[i], v[j]);
    }

    for(int k=1; k<S; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx w(cos(angle), sin(angle));

        for(int i=0; i<S; i+=k*2) {
            cpx z(1, 0);

            for(int j=0; j<k; j++) {
                cpx even = v[i+j];
                cpx odd = v[i+j+k];

                v[i+j] = even + z*odd;
                v[i+j+k] = even - z*odd;

                z *= w;
            }
        }
    }

    if(inv)
        for(int i=0; i<S; i++) v[i] /= S;
}

vector<int> mul(vector<int> &v, vector<int> &u) {
    vector<cpx> vc(v.begin(), v.end());
    vector<cpx> uc(u.begin(), u.end());

    int S = 2;
    while(S < v.size() + u.size()) S *= 2;

    vc.resize(S); FFT(vc, false);
    uc.resize(S); FFT(uc, false);

    for(int i=0; i<S; i++) vc[i] *= uc[i];
    FFT(vc, true);

    vector<int> w(S);
    for(int i=0; i<S; i++) w[i] = round(vc[i].real());

    return w;
}
int N,M;
int main() {
    fast_io();
    cin>>N;
    vector<int> vec(200001,0);
    for(int x=0;x<N;x++){
        int input;
        cin>>input;
        chk[input]=true;
        vec[input]++;
    }
    vector<int> w = mul(vec,vec);
    for(int x=0;x<200001;x++){
        if(w[x]){
            chk[x]=true;
        }
    }
    cin>>M;
    int solve=0;
    for(int x=0;x<M;x++){
        int input;
        cin>>input;
        if(chk[input]) solve++;
    }
    cout<<solve;
}