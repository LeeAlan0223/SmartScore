# SmartScore 成績管理系統

![version](https://img.shields.io/badge/version-v2.0-blue)
![language](https://img.shields.io/badge/language-C-lightgrey)
![status](https://img.shields.io/badge/status-developing-yellow)

版本：v2.0

這是一個用 C 語言開發的 CLI 學生成績輸入與統計工具，從基礎功能一路升級至完整防呆與資料儲存系統。

---

## 功能特色
- 成績輸入（含錯誤防呆：負數 / 超過 100 / 非整數）
- 顯示所有成績
- 計算平均分數
- 顯示最高分與最低分
- 成績分布圖（以星號 * 表示）
- 儲存所有成績與統計資訊到 `scores.txt`
- 支援跨平台清除畫面（Windows / Linux）

---

## 使用方式
1. 編譯程式：gcc smartscore.c -o smartscore
2. 執行程式：./smartscore

---

## 版本紀錄

### v1.0 初版
- 支援基本成績輸入功能
- 計算並顯示班級平均分數
- 找出最高分與最低分
- 列印所有輸入的成績
- 成績分布依區間分組並以星號顯示
- 資料儲存將所有成績與統計結果儲存至 `scores.txt`
- 基礎流程控制，無錯誤防呆

### v2.0 升級版
- **模組化重構**：各功能分為獨立函式（輸入、輸出、統計、儲存）
- **強化錯誤防呆**：輸入錯誤（負數、超過100、非整數）可即時偵測並重新輸入
- **新增指標傳遞**：平均、總分、最高分、最低分皆以指標更新
- **跨平台支援**：新增 `clear()` 函式，Windows / Mac / Linux皆能清除畫面
- **程式內部增加完整中文註解**，方便自學與維護
- **錯誤暫停與畫面清除**流程優化（`error_pause()` 模組）

---

## 開發者筆記
本作品使用模組化設計，提升可讀性與可維護性。

主要函式功能：
- `input_scores()`：成績輸入與錯誤防呆
- `output_scores()`：列印成績與計算平均、最高、最低分
- `ranked_and_distribution()`：繪製成績分布統計圖
- `save_scores_to_file()`：將成績及統計資料寫入外部檔案
- `pause()`、`clear()`、`error_pause()`：畫面控制與錯誤處理模組

---

## 作者
李承恩 / Alan Lee  
學號：1113415026  
班級：電信一甲

