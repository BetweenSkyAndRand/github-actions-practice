#ifndef SCORE_RANK_HPP
#define SCORE_RANK_HPP

// スコアを分類する種類．
enum class ScoreRank {
    S,
    A,
    B,
    C,
    Invalid
};

// 0〜100点のスコアをランクに分類する．範囲外はInvalidを返す．
ScoreRank classify_score(int score);

// ランクを表示用の短い文字列へ変換する．
const char* rank_name(ScoreRank rank);

#endif  // SCORE_RANK_HPP
