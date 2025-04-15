#include <stdio.h>
#include <stdlib.h>

/*	
	---------------�`�ѰO----------------- 
	static(�R�A�ܼ�)
	--------------�}�C�֤�---------------- 
	�}�C�۷��@�ӽc�l�̭��s���ܦh�����
	�]�N�O�@�Ӥ@���ܼƪ����X
	--------------�Ψ쪺�y�k----------------
	const(�T�w):�Ω󤣷|��諸�ܼ�
	char*�]�r����С^�G�Ψӫ��V�@�q�r�ꪺ�}�Y��m
	
	--------------�إ�.txt��----------------
	�Ĥ@�B:�}���ɮשΫإߡBŪ���C
	  
	FILE *f = fopen("scores.txt", "a");
	
	FILE �Ψ�Ū�g�ɮת��u��]�i�H�������c 
	f �O file ���Y�g  
	fopen �����W�s file open
	 
	"r"		read	�uŪ�A�ɮץ����s�b�A�_�h����
	"w"		write	�u�g�A�ɮפ��s�b�N�إߡB�s�b�N�M��
	"a"		append	�u�g�A���|�M�Ť��e�A�|���b�ɮק���
	======================================================= 
	"r+"			Ū�g	�i�HŪ�]�i�H�g�A������s��
	"w+"			Ū�g	�i�HŪ�]�i�H�g�A�|�M�Ť��e
	"a+"			Ū�g	�i�HŪ�]�i�H�g�A�g���|�[�b�᭱
	*******************************************************
	�ĤG�B:�P�_�O���\����C 
	 
	if (f == NULL){
    printf("�}�ɥ���\n");
    return;
	}
		
	NULL �S�����\���N��o�̫� "�S���}�ҫ��w�ɮ�" 
	*******************************************************
	�ĥ|�B:
	fprintf(f,"");
	
	�򥻴N��printf�t���h�N�O�t�b��ܪ��a�褣�P
	
	�t�O
	printf:�C�L�b�ù� 
	fprintf:�C�L�b�ɮפ��ҳ]�w���ɮצ����ڳo�̳]�w��.txt�� 
	
	(f,):�o�̬O�ܼƫإߪ��W��
	(f,""):�޸����񤺮e
	*******************************************************
	�Ĥ��B(�̫�@�B):�����ɮ�
	 
	fclose(f);  
	  
*/ 

// �U�ӼҲժ��禡�쫬�ŧi(�]�����ݭn�^�Ǫ���void�Φ��Y�i) 
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

	// �ϥΪ̿�J�ҸդH��
	printf("---------|��J�ҸդH��|---------\n");
	printf("�п�J�ҸդH��:");
	if(scanf("%d", &number)!=1){
		printf("\n-------------|���~|-------------\n");
		printf("�A��J�����O��Ƴ�I\n");
		pause();
		return 1;
	}
	printf("\n");
	

	// �򥻿�J�ˬd�G�H�Ƥ��o���t
	if (number < 0) {
		printf("\n-------------|���~|-------------\n");
		printf("�H�Ƥ���O�t��\n");
		pause();
		return 1;
	}

	// �ŧi���Z�}�C�]�b�ʺA�^
	int score[number];

	// �̧ǩI�s�U�\��Ҳ�
	printf("-----------|��J���Z|-----------\n");
	input_scores(score, number);
	
	if(error==1){
		return 1;
	}

	printf("-----------|�C�L���Z|-----------\n");
	output_scores(score, number);
	printf("�Ҧ����Z�w��J�����I\n\n");

	printf("-----------|�Z�ť���|-----------\n");
	average_score(score, number);
	max_and_min(score, number);

	printf("---------|�Z�űƦW����|---------\n");
	ranked_and_distribution(score, number);

	printf("-----------|���ӷs�W|-----------\n");
	printf("\n");
	printf("\t      �ȵL\t\n");
	printf("\n");
	printf("--------------------------------\n");
	
	save_scores_to_file(score, number);
	
	pause();
	return 0;
}

// �Ҳ� 1�G��J�C��ǥͪ����Z�A���ˬd���ର�t��
void input_scores(int arr[], int n){
	for (int x = 0; x < n; x++) {
		printf("�п�J�� %d �Ӧ��Z:", x + 1);
		if (scanf("%d", &arr[x])!=1){
			printf("\n-------------|���~|-------------\n");
			printf("�A��J�����O��Ƴ�I\n");
			pause();
	    	error=1;
			return;
		}

		if (arr[x] < 0) {
			printf("\n-------------|���~|-------------\n");
			printf("���Z����O�t��\n");
			pause();
			error=1;
			return;
		}
		if (arr[x] >100) {
			printf("\n-------------|���~|-------------\n");
			printf("���Z����W�L100\n");
			pause();
			error=1;
			return;
		}
	}		
}

// �Ҳ� 2�G�L�X�Ҧ���J�����Z
void output_scores(int arr[], int n){
	for (int x = 0; x < n; x++) {
		printf("�� %d �Ӧ��Z: %3d\n", x + 1, arr[x]);
	}
}

// �Ҳ� 3�G�p��ÿ�X�Z�ť������Z
void average_score(int arr[], int n){
	double average = 0.0;
	for (int x = 0; x < n; x++) {
		average += arr[x];
	}
	printf("�Z�ť����O: %.2lf\n", average / n);
}

// �Ҳ� 4�G��X�̰��P�̧C���Ψ�����ǥͽs��
void max_and_min(int arr[], int n){
	int max_score, min_score;
	int max_number = 1;
	int min_number = 1;

	for (int x = 0; x < n; x++) {
		if (x == 0) {
			// ��l�]�w�G�βĤ@��ǥͪ����Z�@���_�l������
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
	printf("�̰������O��%3d �Ӧ��Z�O: %3d\n", max_number, max_score);
	printf("�̧C�����O��%3d �Ӧ��Z�O: %3d\n", min_number, min_score);
}

// �Ҳ� 5�G�έp�U���Z�϶��������åάP�� * �ϥ�
void ranked_and_distribution(int arr[], int n){
	int Grade_distribution[10] = {0}; // �����϶��G100~90, 89~80, ..., 9~0

	// �϶�����
	const char* Rank[10] = {
		"100~90:", "89~80: ", "79~70: ", "69~60: ",
		"59~50: ", "49~40: ", "39~30: ", "29~20: ",
		"19~10: ", "9~0:   "
	};

	// �έp�C��P�Ǫ����Z����������϶�
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

	// ��ܤ�����
	for (int i = 0; i < 10; i++) {
		printf("%s ", Rank[i]);
		for (int j = 0; j < Grade_distribution[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}

// �Ҳ� 6�G�x�s��J���Z 
void save_scores_to_file(int arr[], int n){
	
	double average = 0.0;
	
	int max_score, min_score;
	int max_number = 1;
	int min_number = 1;
	
	FILE *f = fopen("scores.txt", "a");
	
	if (f == NULL){
	printf("\n-------------|���~|-------------\n");
    printf("�}�ɥ���QQ\n");
    return;
	}
	
	fprintf(f,"-----------|�C�L���Z|-----------\n"); 
	for (int c = 0; c < n; c++) {
		fprintf(f,"�� %d �Ӧ��Z: %3d\n", c + 1, arr[c]);
	}
	
	fprintf(f,"-----------|�Z�ť���|-----------\n");	
	for (int y = 0; y < n; y++) {
		average += arr[y];
	}
	fprintf(f,"�Z�ť����O: %.2lf\n", average / n);
	
	for (int z = 0; z < n; z++) {
		if (z == 0) {
			// ��l�]�w�G�βĤ@��ǥͪ����Z�@���_�l������
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
	fprintf(f,"�̰������O��%3d �Ӧ��Z�O: %3d\n", max_number, max_score);
	fprintf(f,"�̧C�����O��%3d �Ӧ��Z�O: %3d\n", min_number, min_score);
	
	fprintf(f,"---------|�Z�űƦW����|---------\n");
		int Grade_distribution[10] = {0}; // �����϶��G100~90, 89~80, ..., 9~0

	// �϶�����
	const char* Rank[10] = {
		"100~90:", "89~80: ", "79~70: ", "69~60: ",
		"59~50: ", "49~40: ", "39~30: ", "29~20: ",
		"19~10: ", "9~0:   "
	};

	// �έp�C��P�Ǫ����Z����������϶�
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

	// ��ܤ�����
	for (int i = 0; i < 10; i++) {
		fprintf(f,"%s ", Rank[i]);
		for (int j = 0; j < Grade_distribution[i]; j++) {
			fprintf(f,"*");
		}
		fprintf(f,"\n");
	}
	
	fprintf(f,"-----------|�C�L����|-----------\n");
	fprintf(f,"\n\n");
	
	printf("\n------------|�w����|------------\n");
	printf("�w�إ� scores.txt �� !\n");
	
	fclose(f);
}

void pause(void){
	printf("�Ы�Enter����...\n");
	printf("--------------------------------\n");
	while (getchar() != '\n');	// �M���w�İϪ��r��
    getchar();	// ���ݨϥΪ̫��U Enter ��
}
