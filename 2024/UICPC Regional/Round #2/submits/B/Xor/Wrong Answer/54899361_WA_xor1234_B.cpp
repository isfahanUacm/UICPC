#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T; // Number of test cases
    cin >> T;
    
    while (T--) {
        int Q, M;
        cin >> Q >> M;
        
        vector<char> answers(Q, '?'); // This will store the final answers for each question
        
        // Loop over each student's corrected paper
        for (int i = 0; i < M; ++i) {
            vector<pair<char, char>> paper(Q); // To store (answer, correctness) for each question in the paper
            
            for (int j = 0; j < Q; ++j) {
                char studentAnswer, correctness;
                cin >> studentAnswer >> correctness;
                paper[j] = {studentAnswer, correctness};
            }
            
            // Now analyze the student's paper
            for (int j = 0; j < Q; ++j) {
                if (paper[j].second == 'T') { // If the student's answer is correct
                    if (answers[j] == '?') { // If we haven't determined the answer yet
                        answers[j] = paper[j].first; // Set the correct answer
                    } else if (answers[j] != paper[j].first) {
                        // If there's a conflict (different correct answers), mark it as uncertain
                        answers[j] = '?';
                    }
                }
            }
        }
        
        // Output the results for this test case
        for (int i = 0; i < Q; ++i) {
            cout << answers[i];
            if (i < Q - 1) cout << ' '; // Space between answers, but not at the end
        }
        cout << endl;
    }
    
    return 0;
}
