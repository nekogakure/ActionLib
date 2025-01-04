#include "catLog.h"

void catLog_clear() {
    // ログファイルを開いて内容を消去（上書き）
    FILE *logfile = fopen(LOG_FILE, "w");
    if (logfile != NULL) {
        fclose(logfile);  // ファイルを閉じて内容を消去
    } else {
        perror("Error clearing log file");
    }
}

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