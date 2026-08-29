# ================================================================
# Makefile
#
# 目的：スコア判定プログラムをビルド，実行，テストする．
# 使い方：make / make run / make test / make clean / make help
# ================================================================

CXX ?= g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude

BUILD_DIR := build

APP := $(BUILD_DIR)/score_rank_app
TEST := $(BUILD_DIR)/test_score_rank

APP_OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/score_rank.o
TEST_OBJS := $(BUILD_DIR)/test_score_rank.o $(BUILD_DIR)/score_rank.o
DEPS := $(APP_OBJS:.o=.d) $(TEST_OBJS:.o=.d)

.PHONY: all run test clean help

all: $(APP)

# アプリケーションをリンクして実行ファイルを作る．
$(APP): $(APP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# テスト用プログラムをリンクして実行ファイルを作る．
$(TEST): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# src内の.cppを，対応する.oへコンパイルする．-MMD -MPはヘッダ依存を自動作成する．
$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# tests内のテスト用.cppを，対応する.oへコンパイルする．
$(BUILD_DIR)/test_%.o: tests/test_%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# ビルド用ディレクトリがなければ作る．
$(BUILD_DIR):
	mkdir -p $@

# ビルドしたプログラムを実行する．必要なら先にビルドする．
run: $(APP)
	./$(APP)

# テストを実行する．テストプログラムの終了コードがmakeの結果になる．
test: $(TEST)
	./$(TEST)

# この演習で作るファイルだけを明示して削除する．rm -rfは使わない．
clean:
	rm -f $(APP) $(TEST) $(APP_OBJS) $(TEST_OBJS) $(DEPS)
	rmdir $(BUILD_DIR) 2>/dev/null || true

# 利用できるターゲットを表示する．
help:
	@echo "利用方法"
	@echo "  make        アプリケーションをビルドします"
	@echo "  make run    ビルド後にアプリケーションを実行します"
	@echo "  make test   テストをビルドして実行します"
	@echo "  make clean  この演習で生成したbuild内のファイルだけを削除します"
	@echo "  make help   この説明を表示します"

# ヘッダーファイルを変更したときにも必要な.oを再コンパイルする．
-include $(DEPS)
