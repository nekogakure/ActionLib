#include "catLog.h"
#include <string.h>

int main(int argc, char *argv[]) {
    // コマンドライン引数が '--clear' であればログをクリア
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--clear") == 0) {
            catLog_clear();
            catLog("Log has been cleared.");
            return 0;  // ログがクリアされたら処理を終了
        }
    }

    // 通常のログ処理
    catLog("This is catLog test.");
    
    int i = 0;
    
    while (i < 10) {
        catLog("Current value of i: ");
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d", i);
        catLog(buffer);
        i++;
    }
    
    return 0;
}
