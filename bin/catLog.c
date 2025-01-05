#include "../include/catLog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// グローバル設定
static char LOG_FILE[256] = "cat.log";  // デフォルトログファイル名
static int CATLOG = 1;                      // デフォルトでログを有効化

void catLog_conf_FILE(const char *logFile) {
    LOG_FILE[256] = logFile;
}

void catLog_conf_IO(int catlog) {
    CATLOG = catlog;
}


// ログファイルを消去する関数
void catLog_clear() {
    // ログ出力が有効な場合のみ実行
    if (CATLOG) {
        FILE *logfile = fopen(LOG_FILE, "w");
        if (logfile != NULL) {
            fclose(logfile);  // ファイルを閉じて内容を消去
        } else {
            perror("Error clearing log file");
        }
    }
}

// ログを書き込む関数
void catLog(const char *message) {
    if (CATLOG) {
        // 現在の時間を取得
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        // ログファイルを開く（追記モード）
        FILE *logfile = fopen(LOG_FILE, "a");
        if (logfile != NULL) {
            // フォーマットに従ってログメッセージを記録
            fprintf(logfile, "[%04d/%02d/%02d] %02d:%02d:%02d - %s\n",
                    tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,  // 日付
                    tm.tm_hour, tm.tm_min, tm.tm_sec,               // 時刻
                    message);
            fclose(logfile);
        } else {
            perror("Error opening log file");
        }
    }
}
