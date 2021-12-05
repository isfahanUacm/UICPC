#include <bits/stdc++.h>
using namespace std;
#define Max_n 400010
int M, N, lps[Max_n];
int pat[Max_n], txt[Max_n];
bool res = false;
int clock1[Max_n], clock2[Max_n];
void calcLPS() 
{ 
	int len = 0; 
	lps[0] = 0;
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else 
		{ 
			if (len != 0) { 
				len = lps[len - 1];  
			} 
			else
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

void KMPSearch() 
{   
    
	calcLPS();
    
	int i = 0; // index of txt
	int j = 0; // index of pattern
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 
		if (j == M) { 
			// find a full match: print answer or store it
            res = true;
			j = lps[j - 1]; 
		}  
		else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

int main()
{
    cin >> N;
    M = N;
    for (int i = 0; i < N; ++i)
        cin >> clock1[i];
    for (int i = 0; i < N; ++i)
        cin >> clock2[i];    
    sort(clock1, clock1+N);
    sort(clock2, clock2+N);
    N *= 2;
    for (int i = 0; i < N; ++i){
        if((i+1)%M){
            txt[i] = clock1[(i+1)%M] - clock1[i%M];
        }
        else{
            txt[i] = clock1[(i+1)%M] + (360000 - clock1[i%M]);
        }        
//        cout<<txt[i];
    }
//    cout << endl;
    for (int i = 0; i < M; ++i) {
        if((i+1)%M)
            pat[i] = clock2[(i+1)] - clock2[i];
        else
            pat[i] = clock2[(i+1)%M] + (360000 - clock2[i%M]);
//        cout<<pat[i];
    }
//    cout << endl;
    KMPSearch();
    if(res){
        cout << "possible" << endl;
    }
    else{
        cout << "impossible" << endl;
    }
    return 0;
}

