#include<stdio.h>
#include<stdlib.h>

/*
	---------------重點---------------
	指標 :記憶體位址，供主程式或其他函式讀取或修改
	比喻 :指標像是一個網站連結或道路地址供通往此地查看
	常見用法如: * 和 &  
*/
 
 // 用了int形式的函式，有return(回傳值)這裡用於檢查執行是否有錯誤 
int input_scores(int arr[], int n,int *totlo);

 // 下列各個模組的函式原型宣告(因為不需要回傳直用void形式即可)
void number_of_people(int *number); 
void output_scores(int arr[], int n,int *max_score,int *min_score,int *max_number,int *min_number ,double *average_score);
void ranked_and_distribution(int arr[], int n,int Grade_distribution[]);
void save_scores_to_file(int arr[], int n,int *max_score,int *min_score,int *max_number,int *min_number ,double *average_score,int Grade_distribution[]);
void clear(void);
void error_pause(void);
void pause(void);


int main(void){
	
	//主變數宣告 (因為用了指標主程式只需要提供變數 "原物料" ) 
	int number;
	int totlo = 0;  
	int max_s = 1 , min_s = 1;
	int max_n = 1 , min_n = 1;
	double average = 0.0 ;
	//初始化陣列變數
	int Grade_distribution[10] = {0}; // 分布區間：100~90, 89~80, ..., 9~0
	 
	 
	// 使用者輸入考試人數(小更動:用while可以錯誤重新輸入) 
	number_of_people(&number);
	 	
	int score[number]; //宣告陣列變數範圍 
	
	while(true){// 使用者輸入考試成績(小更動:用while可以錯誤重新輸入) 
		
		printf("-----------|輸入成績|-----------\n");
		
		if(input_scores(score,number,&totlo) !=0 ){
			printf("請重新輸入成績!\n");
			error_pause();	
			printf("-----------|考試人數|-----------\n");
			printf("考試人數: %d\n",number);
			continue;	//輸入錯誤就重新輸入
		}
		break;	//執行結束跳出無窮迴圈(while) 
	}
	
	printf("-----------|列印成績|-----------\n");
	//用指標 " * " 對應 " & " 供函式記憶體位置	
	output_scores( score, number, &max_s, &min_s, &max_n, &min_n, &average);
	printf("-----------|班級平均|-----------\n");
	printf("班級平均是: %.2lf\n", average);
	printf("最高分的是第%3d 個成績是: %3d\n", max_n, max_s);
	printf("最低分的是第%3d 個成績是: %3d\n", min_n, min_s);
	
	printf("---------|班級排名分布|---------\n");
	ranked_and_distribution(score, number, Grade_distribution);
	
	printf("-----------|未來新增|-----------\n");
	printf("\n");
	printf("\t      暫無\t\n");
	printf("\n");
	printf("--------------------------------\n");
	save_scores_to_file( score, number, &max_s, &min_s, &max_n, &min_n, &average, Grade_distribution);
	printf("請按Enter結束...\n");	
	pause();
	return 0;
}

void number_of_people(int *number){
	
		while(true){
		printf("---------|輸入考試人數|---------\n");
		printf("請輸入考試人數:");
		if( scanf("%d", number) != 1){
		 
		printf("\n-------------|錯誤|-------------\n");
		
		printf("你輸入的不是整數喔！\n");
		printf("請重新輸入考試人數!\n");
		error_pause();
		continue;	//輸入錯誤就重新輸入
		
		}
		
		// 基本輸入檢查：人數不得為負
		if (*number < 0) {
			printf("\n-------------|錯誤|-------------\n");
			printf("人數不能是負數\n");
			printf("請重新輸入考試人數!\n");
			error_pause();	
			continue;	//輸入錯誤就重新輸入 
		}
		printf("\n");
		break;	
	}
}

int input_scores(int arr[], int n,int *totlo){
	for (int x = 0; x < n; x++) {
		printf("請輸入第 %d 個成績:", x + 1);
		if (scanf("%d", &arr[x])!=1){
			printf("\n-------------|錯誤|-------------\n");
			printf("你輸入的不是整數喔！\n");
			return 1;//回傳值(供主成式判斷是否有執行失敗) 
		}

		if (arr[x] < 0) {
			printf("\n-------------|錯誤|-------------\n");
			printf("成績不能是負數\n");
			return 1;//回傳值(供主成式判斷是否有執行失敗)
		}
		if (arr[x] >100) {
			printf("\n-------------|錯誤|-------------\n");
			printf("成績不能超過100\n");
			return 1;//回傳值(供主成式判斷是否有執行失敗)
		}
		*totlo+=arr[x];	//計算總分 
	}
	return 0;//回傳值(供主成式判斷是否有執行失敗)		
}

void output_scores(int arr[], int n,int *max_score,int *min_score,int *max_number,int *min_number,double *average_score){
	for (int x = 0; x < n; x++) {
		if(x == 0){
			*max_score=arr[x];
			*min_score=arr[x];
		}
		
		if(arr[x] > *max_score){
			*max_number = x + 1;
			*max_score=arr[x];
		}
		
		if(arr[x] < *min_score){
		*min_number = x + 1;
		*min_score=arr[x];
		}
		
		*average_score += arr[x];
		
		printf("第 %d 個成績: %3d\n", x + 1, arr[x]);
	}
	
	*average_score /= n;  //計算平均值 
}

void ranked_and_distribution(int arr[], int n,int Grade_distribution[]){
	

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

void save_scores_to_file(int arr[], int n,int *max_score,int *min_score,int *max_number,int *min_number ,double *average_score ,int Grade_distribution[]){
	
	FILE *f = fopen("scores.txt", "a");
	
	if (f == NULL){
	printf("\n-------------|錯誤|-------------\n");
    printf("開檔失敗QQ\n");
    return;
	}
	
	fprintf(f,"-----------|列印成績|-----------\n");
	 
	for (int x = 0; x < n; x++) {
		fprintf(f,"第 %d 個成績: %3d\n", x + 1, arr[x]);
	}	
	
	fprintf(f,"-----------|班級平均|-----------\n");
		
	fprintf(f,"班級平均是: %.2lf\n",*average_score);
	fprintf(f,"最高分的是第%3d 個成績是: %3d\n", *max_number, *max_score);
	fprintf(f,"最低分的是第%3d 個成績是: %3d\n", *min_number, *min_score);
	
	fprintf(f,"---------|班級排名分布|---------\n");
	
	// 區間標籤
	const char* Rank[10] = {
		"100~90:", "89~80: ", "79~70: ", "69~60: ",
		"59~50: ", "49~40: ", "39~30: ", "29~20: ",
		"19~10: ", "9~0:   "
	};

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

void clear(void){
	/*
		system("cls");只接受 windows系統
		
		system("clear"); 可接受 Mac 和 Linux 
		
	*/ 
	#ifdef _WIN32 //判斷是否是windows系統 
	    system("cls");
	    
	#else
	    system("clear"); //不是就用這個 
	    
	#endif
}

void error_pause(void){	
	printf("請按Enter繼續...\n");
	pause();
	clear();
}

void pause(void){
	printf("--------------------------------\n");
	while (getchar() != '\n');	// 清除緩衝區的字符
    getchar();	// 等待使用者按下 Enter 鍵 
}
