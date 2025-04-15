# SmartScore 成績管理系統

這是一個用 C 語言開發的 CLI 學生成績輸入與統計工具。

## 功能特色
- 成績輸入（含錯誤防呆：負數 / 超過 100 / 非整數）
- 顯示所有成績
- 計算平均分數
- 顯示最高分與最低分
- 成績分布圖（以星號 * 表示）
- 儲存所有成績與統計資訊到 `scores.txt`

## 使用方式
1. 編譯程式：
   ```
   gcc smartscore.c -o smartscore
   ```
2. 執行程式：
   ```
   ./smartscore
   ```

## 開發者筆記
本作品用模組化方式編寫，所有功能分為多個函式：
- `input_scores()`：輸入與錯誤檢查
- `average_score()`、`max_and_min()`：統計計算
- `ranked_and_distribution()`：星號統計圖
- `save_scores_to_file()`：寫入檔案

程式碼含詳細註解，可供學習與二次開發使用。

## 作者
李承恩 / Alan Lee  
學號：1113415026  
班級：電信一甲
