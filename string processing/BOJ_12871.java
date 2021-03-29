import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();
		String tmpA = a;
		String tmpB = b;
		boolean flag = true;
		while(tmpA.length() != tmpB.length()){
			if(tmpA.length()>tmpB.length()){
				tmpB += b;
			}else{
				tmpA += a;
			}
		}
		if(tmpA.equals(tmpB)) System.out.println(1);
		else System.out.println(0);
	}
}
