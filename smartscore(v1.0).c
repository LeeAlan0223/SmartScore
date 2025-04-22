#include <stdio.h>
#include <stdlib.h>

/*	
	---------------常忘記----------------- 
	static(靜態變數)
	--------------陣列核心---------------- 
	陣列相當於一個箱子裡面存取很多的資料
	也就是一個一個變數的集合
	--------------用到的語法----------------
	const(固定):用於不會更改的變數
	char*（字串指標）：用來指向一段字串的開頭位置
	
	--------------建立.txt檔----------------
	第一步:開啟檔案或建立、讀取。
	  
	FILE *f = fopen("scores.txt", "a");
	
	FILE 用來讀寫檔案的工具也可以說式結構 
	f 是 file 的縮寫  
	fopen 的全名叫 file open
	 
	"r"		read	只讀，檔案必須存在，否則失敗
	"w"		write	只寫，檔案不存在就建立、存在就清空
	"a"		append	只寫，不會清空內容，會接在檔案尾端
	======================================================= 
	"r+"			讀寫	可以讀也可以寫，但不能新建
	"w+"			讀寫	可以讀也可以寫，會清空內容
	"a+"			讀寫	可以讀也可以寫，寫的會加在後面
	*******************************************************
	第二步:判斷是成功執行。 
	 
	if (f == NULL){
    printf("開檔失敗\n");
    return;
	}
		
	NULL 沒有成功的意思這裡指 "沒有開啟指定檔案" 
	*******************************************************
	第三步:
	fprintf(f,"");
	
	基本就跟printf差不多就是差在顯示的地方不同
	
	差別
	printf:列印在螢幕 
	fprintf:列印在檔案內所設定的檔案有關我這裡設定成.txt檔 
	
	(f,):這裡是變數建立的名稱
	(f,""):引號內放內容
	*******************************************************
	第四步(最後一步):關閉檔案
	 
	fclose(f);  
	  
*/ 

// 各個模組的函式原型宣告(因為不需要回傳直用void形式即可) 
void input_scores(int arr[], int n); 
void output_scores(int arr[], int n); 
void average_score(int arr[], int n);
void max_and_min(int arr[], int n);
void ranked_and_distribution(int arr[], int n);
void save_scores_to_file(int arr[], int n);
void pause(void);

int error=0; 

int main(){
	int number;

	// 使用者輸入考試人數
	printf("---------|輸入考試人數|---------\n");
	printf("請輸入考試人數:");
	if(scanf("%d", &number)!=1){
		printf("\n-------------|錯誤|-------------\n");
		printf("你輸入的不是整數喔！\n");
		pause();
		return 1;
	}
	printf("\n");
	

	// 基本輸入檢查：人數不得為負
	if (number < 0) {
		printf("\n-------------|錯誤|-------------\n");
		printf("人數不能是負數\n");
		pause();
		return 1;
	}

	// 宣告成績陣列（半動態）
	int score[number];

	// 依序呼叫各功能模組
	printf("-----------|輸入成績|-----------\n");
	input_scores(score, number);
	
	if(error==1){
		return 1;
	}

	printf("-----------|列印成績|-----------\n");
	output_scores(score, number);
	printf("所有成績已輸入完畢！\n\n");

	printf("-----------|班級平均|-----------\n");
	average_score(score, number);
	max_and_min(score, number);

	printf("---------|班級排名分布|---------\n");
	ranked_and_distribution(score, number);

	printf("-----------|未來新增|-----------\n");
	printf("\n");
	printf("\t      暫無\t\n");
	printf("\n");
	printf("--------------------------------\n");
	
	save_scores_to_file(score, number);
	
	pause();
	return 0;
}

// 模組 1：輸入每位學生的成績，並檢查不能為負數
void input_scores(int arr[], int n){
	for (int x = 0; x < n; x++) {
		printf("請輸入第 %d 個成績:", x + 1);
		if (scanf("%d", &arr[x])!=1){
			printf("\n-------------|錯誤|-------------\n");
			printf("你輸入的不是整數喔！\n");
			pause();
	    	error=1;
			return;
		}

		if (arr[x] < 0) {
			printf("\n-------------|錯誤|-------------\n");
			printf("成績不能是負數\n");
			pause();
			error=1;
			return;
		}
		if (arr[x] >100) {
			printf("\n-------------|錯誤|-------------\n");
			printf("成績不能超過100\n");
			pause();
			error=1;
			return;
		}
	}		
}

// 模組 2：印出所有輸入的成績
void output_scores(int arr[], int n){
	for (int x = 0; x < n; x++) {
		printf("第 %d 個成績: %3d\n", x + 1, arr[x]);
	}
}

// 模組 3：計算並輸出班級平均成績
void average_score(int arr[], int n){
	double average = 0.0;
	for (int x = 0; x < n; x++) {
		average += arr[x];
	}
	printf("班級平均是: %.2lf\n", average / n);
}

// 模組 4：找出最高與最低分及其對應學生編號
void max_and_min(int arr[], int n){
	int max_score, min_score;
	int max_number = 1;
	int min_number = 1;

	for (int x = 0; x < n; x++) {
		if (x == 0) {
			// 初始設定：用第一位學生的成績作為起始比較基準
			max_score = arr[x];
			min_score = arr[x];
		} else {
			if (arr[x] > max_score) {
				max_score = arr[x];
				max_number = x + 1;
			}
			if (arr[x] < min_score) {
				min_score = arr[x];
				min_number = x + 1;
			}
		}
	}
	printf("最高分的是第%3d 個成績是: %3d\n", max_number, max_score);
	printf("最低分的是第%3d 個成績是: %3d\n", min_number, min_score);
}

// 模組 5：統計各成績區間的分布並用星號 * 圖示
void ranked_and_distribution(int arr[], int n){
	int Grade_distribution[10] = {0}; // 分布區間：100~90, 89~80, ..., 9~0

	// 區間標籤
	const char* Rank[10] = {
		"100~90:", "89~80: ", "79~70: ", "69~60: ",
		"59~50: ", "49~40: ", "39~30: ", "29~20: ",
		"19~10: ", "9~0:   "
	};

	// 統計每位同學的成績分布到對應區間
	for (int x = 0; x < n; x++) {
		if (arr[x] >= 90)
			Grade_distribution[0]++;
		else if (arr[x] >= 80)
			Grade_distribution[1]++;
		else if (arr[x] >= 70)
			Grade_distribution[2]++;
		else if (arr[x] >= 60)
			Grade_distribution[3]++;
		else if (arr[x] >= 50)
			Grade_distribution[4]++;
		else if (arr[x] >= 40)
			Grade_distribution[5]++;
		else if (arr[x] >= 30)
			Grade_distribution[6]++;
		else if (arr[x] >= 20)
			Grade_distribution[7]++;
		else if (arr[x] >= 10)
			Grade_distribution[8]++;
		else
			Grade_distribution[9]++;
	}

	// 顯示分布圖
	for (int i = 0; i < 10; i++) {
		printf("%s ", Rank[i]);
		for (int j = 0; j < Grade_distribution[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}

// 模組 6：儲存輸入成績 
void save_scores_to_file(int arr[], int n){
	
	double average = 0.0;
	
	int max_score, min_score;
	int max_number = 1;
	int min_number = 1;
	
	FILE *f = fopen("scores.txt", "a");
	
	if (f == NULL){
	printf("\n-------------|錯誤|-------------\n");
    printf("開檔失敗QQ\n");
    return;
	}
	
	fprintf(f,"-----------|列印成績|-----------\n"); 
	for (int c = 0; c < n; c++) {
		fprintf(f,"第 %d 個成績: %3d\n", c + 1, arr[c]);
	}
	
	fprintf(f,"-----------|班級平均|-----------\n");	
	for (int y = 0; y < n; y++) {
		average += arr[y];
	}
	fprintf(f,"班級平均是: %.2lf\n", average / n);
	
	for (int z = 0; z < n; z++) {
		if (z == 0) {
			// 初始設定：用第一位學生的成績作為起始比較基準
			max_score = arr[z];
			min_score = arr[z];
		} else {
			if (arr[z] > max_score) {
				max_score = arr[z];
				max_number = z + 1;
			}
			if (arr[z] < min_score) {
				min_score = arr[z];
				min_number = z + 1;
			}
		}
	}
	fprintf(f,"最高分的是第%3d 個成績是: %3d\n", max_number, max_score);
	fprintf(f,"最低分的是第%3d 個成績是: %3d\n", min_number, min_score);
	
	fprintf(f,"---------|班級排名分布|---------\n");
		int Grade_distribution[10] = {0}; // 分布區間：100~90, 89~80, ..., 9~0

	// 區間標籤
	const char* Rank[10] = {
		"100~90:", "89~80: ", "79~70: ", "69~60: ",
		"59~50: ", "49~40: ", "39~30: ", "29~20: ",
		"19~10: ", "9~0:   "
	};

	// 統計每位同學的成績分布到對應區間
	for (int x = 0; x < n; x++) {
		if (arr[x] >= 90)
			Grade_distribution[0]++;
		else if (arr[x] >= 80)
			Grade_distribution[1]++;
		else if (arr[x] >= 70)
			Grade_distribution[2]++;
		else if (arr[x] >= 60)
			Grade_distribution[3]++;
		else if (arr[x] >= 50)
			Grade_distribution[4]++;
		else if (arr[x] >= 40)
			Grade_distribution[5]++;
		else if (arr[x] >= 30)
			Grade_distribution[6]++;
		else if (arr[x] >= 20)
			Grade_distribution[7]++;
		else if (arr[x] >= 10)
			Grade_distribution[8]++;
		else
			Grade_distribution[9]++;
	}

	// 顯示分布圖
	for (int i = 0; i < 10; i++) {
		fprintf(f,"%s ", Rank[i]);
		for (int j = 0; j < Grade_distribution[i]; j++) {
			fprintf(f,"*");
		}
		fprintf(f,"\n");
	}
	
	fprintf(f,"-----------|列印結束|-----------\n");
	fprintf(f,"\n\n");
	
	printf("\n------------|已建檔|------------\n");
	printf("已建立 scores.txt 檔 !\n");
	
	fclose(f);
}

void pause(void){
	printf("請按Enter結束...\n");
	printf("--------------------------------\n");
	while (getchar() != '\n');	// 清除緩衝區的字符
    getchar();	// 等待使用者按下 Enter 鍵
}
