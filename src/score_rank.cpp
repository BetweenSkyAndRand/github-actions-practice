#include "score_rank.hpp"

ScoreRank classify_score(int score) {
    if (score < 0 || score > 100) {
        return ScoreRank::Invalid;
    }
    ScoreRank result;
    if (score<50)
    {
        result = ScoreRank::C;
    }
    else if(score<70)
    {
        result=ScoreRank::B;
    }
    else if(score<90)
    {
        result=ScoreRank::A;
    }
    else 
    {
        result=ScoreRank::S;
    }
    return result;

    // TODO： 点数とランク分類を追加する
}

const char* rank_name(ScoreRank rank) {
    switch (rank) {
        case ScoreRank::S:
            return "S";
        case ScoreRank::A:
            return "A";
        case ScoreRank::B:
            return "B";
        case ScoreRank::C:
            return "C";
        case ScoreRank::Invalid:
            return "Invalid";
    }
    return "Invalid";
}
