import java.util.Scanner;
import java.util.Scanner.*;
import java.util.StringTokenizer;
public class Boj_9322 {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int testCase=0;
		testCase=input.nextInt();
		for(int i=0;i<testCase;i++) {
			int wordCnt=0;
			wordCnt=input.nextInt();
			String[] firstPublicKey=new String[wordCnt];
			String[] secondPublicKey=new String[wordCnt];
			String[] code=new String[wordCnt];
			String[] answer=new String[wordCnt];
			int[] index=new int[wordCnt];
			for(int j=0;j<wordCnt;j++) {
				firstPublicKey[j]=input.next();
			}
			for(int j=0;j<wordCnt;j++) {
				secondPublicKey[j]=input.next();
			}
			for(int j=0;j<wordCnt;j++) {
				code[j]=input.next();
			}
			for(int j=0;j<wordCnt;j++) {
				for(int k=0;k<wordCnt;k++) {
					if(secondPublicKey[j].equals(firstPublicKey[k])) {
						index[j]=k;
						answer[k]=code[j];
						break;
					}
				}
			}
			for(int j=0;j<wordCnt;j++) {
				System.out.print(answer[j]+" ");
			}
			System.out.println();
		}
	}

}
