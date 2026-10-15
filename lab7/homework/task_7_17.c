#include <stdio.h>

int main() {
    int n;


    printf("Enter the number of judges n (n >= 3): ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Error: at least 3 scores are required for calculation.\n");
        return 1;
    }

    double current_score, sum = 0.0, max_val, min_val;

    printf("Enter %d scores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &current_score);
        sum += current_score;


        if (i == 0) {
            max_val = current_score;
            min_val = current_score;
        } else {
            // Update maximum and minimum
            if (current_score > max_val) {
                max_val = current_score;
            }
            if (current_score < min_val) {
                min_val = current_score;
            }
        }
    }


    double final_score = (sum - max_val - min_val) / (n - 2);

    printf("The final score for the athlete: %.4lf\n", final_score);

    return 0;
}