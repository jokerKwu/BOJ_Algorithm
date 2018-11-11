import java.util.Scanner;


public class Main {
	static String stringSplit(String str,int idx1,int idx2,int len) {
		String res=null;
		res=Reverse(str.substring(0, idx1+1));

		res+=(Reverse(str.substring(idx1+1,idx2+1)));

		res+=(Reverse(str.substring(idx2+1,len+1)));

		return res;
	}
	//문자열 뒤집는 함수
	public static String Reverse(String s) {
		return(new StringBuffer(s)).reverse().toString();
	}
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		String str=input.nextLine();
		int len=str.length();
		String res=stringSplit(str,0,1,len-1);
		for(int i=0;i<len-2;i++) {
			for(int j=i+1;j<len-1;j++) {
				String tmp=stringSplit(str,i,j,len-1);
				if(res.compareTo(tmp)>0) {
					res=tmp;
				}
			}
		}
		System.out.println(res);
	}
}