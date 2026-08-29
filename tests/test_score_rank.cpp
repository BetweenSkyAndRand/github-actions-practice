#include <iostream>
#include <string>

#include "score_rank.hpp"

namespace {

int failures = 0; // テスト失敗のカウンター

void expect_rank(const std::string& name, int score, ScoreRank expected) {

   // TODO：テストに成功すると，"[PASS]"とテスト名(name)を出力する．
   ScoreRank actual = classify_score(score);
   if(actual==expected){
    std::cout << "[PASS] " << name << '\n';
    std::cout << "       expected: " << rank_name(expected) << '\n';
    }
    else{
        ++failures;
        std::cout << "[FAIL] " << name << '\n';
        std::cout << "       expected: " << rank_name(expected) << '\n';
        std::cout << "       actual  : " << rank_name(actual) << '\n';
    }
}

}  // namespace

int main() {
    // 正常値と，ランクが切り替わる境界値を確認する．
    // 100点の例
    expect_rank("100点はS", 100, ScoreRank::S);
    // TODO：90点のテストを追加する
    expect_rank("90点はS", 90, ScoreRank::S);
    // TODO：89点のテストを追加する
    expect_rank("80点はA", 80, ScoreRank::A);
    // TODO：70点のテストを追加する
    expect_rank("70点はA", 70, ScoreRank::A);
    // TODO：69点のテストを追加する
    expect_rank("60点はB", 60, ScoreRank::B);    
    // TODO：50点のテストを追加する
    expect_rank("50点はB", 50, ScoreRank::B);    
    // TODO：49点のテストを追加する
    expect_rank("49点はC", 49, ScoreRank::C);    
    // TODO： 0点のテストを追加する
    expect_rank("0点はC", 0, ScoreRank::C);
    // 異常値も判定できることを確認する．
    expect_rank("-1点は無効", -1, ScoreRank::Invalid);
    // TODO：101点のテストを追加する．
    expect_rank("101点は無効", 101, ScoreRank::Invalid);
    if (failures == 0) {
        std::cout << "All tests passed." << '\n';
        return 0; // 終了コード
    }

    std::cout << failures << " test(s) failed." << '\n';
    return 1; // 終了コード
}
