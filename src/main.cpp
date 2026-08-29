#include <iostream>

#include "score_rank.hpp"

int main() {
    const int score = 88;
    const ScoreRank rank = classify_score(score);

    std::cout << "Score: " << score << '\n';
    std::cout << "Rank : " << rank_name(rank) << '\n';
    return 0;
}
