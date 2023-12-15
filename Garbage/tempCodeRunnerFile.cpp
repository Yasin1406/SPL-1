#include<bits/stdc++.h>

using namespace std;

// Function to normalize the feature matrix
void normalize(vector<vector<double>>& X) {
    // Perform normalization (mean centering and scaling)
    for (int j = 0; j < X[0].size(); ++j) {
        double mean = 0.0;
        for (int i = 0; i < X.size(); ++i) {
            mean += X[i][j];
        }
        mean /= X.size();

        double stddev = 0.0;
        for (int i = 0; i < X.size(); ++i) {
            X[i][j] -= mean;
            stddev += X[i][j] * X[i][j];
        }

        if (stddev != 0.0) {
            stddev = sqrt(stddev / X.size());

            for (int i = 0; i < X.size(); ++i) {
                X[i][j] /= stddev;
            }
        }
    }
}

// Coordinate Descent algorithm for Least Squares
void coordinateDescent(vector<double>& w, const vector<vector<double>>& X, const vector<double>& y, double alpha, int maxIter) {
    int N = X.size();
    int p = X[0].size();
    
    for (int iterO = 0; iterO < maxIter; ++iterO) {
        // Compute Residuals (r)
        vector<double> r(N, 0.0);
        for (int i = 0; i < N; ++i) {
            double prediction = 0.0;
            for (int j = 0; j < p; ++j) {
                prediction += X[i][j] * w[j];
            }
            r[i] = y[i] - prediction;
        }

        // Inner Loop (Loop P)
        for (int j = 0; j < p; ++j) {
            // Compute the Residual for Feature j (r^-_j)
            double r_minus_j = 0.0;
            for (int i = 0; i < N; ++i) {
                r_minus_j += X[i][j] * w[j];
            }
            r_minus_j = r_minus_j - r[j];

            // Update w_j
            double numerator = 0.0, denominator = 0.0;
            for (int i = 0; i < N; ++i) {
                numerator += X[i][j] * r_minus_j;
                denominator += X[i][j] * X[i][j];
            }

            if (denominator != 0.0) {
                w[j] = w[j] + alpha * numerator / denominator;
            }
        }
    }
}

int main() {
    // Example usage
    // Initialize your feature matrix X, target variable y, and parameters
    vector<vector<double>> X = {{7,1.0, 5}, {4.0, 3.0,5}, {6,1,2}};
    vector<double> y = {27,21,9};
    vector<double> weights(X[0].size(), 0.0); // Initialize weights with zeros
    double alpha = 0.1; // Learning rate
    int maxIter = 100; // Maximum number of iterations

    // Normalize the feature matrix
    normalize(X);

    // Run Coordinate Descent
    coordinateDescent(weights, X, y, alpha, maxIter);

    // Output the final weights
    cout << "Final Weights: ";
    for (double weight : weights) {
        cout << weight << " ";
    }
    cout << endl;

    return 0;
}