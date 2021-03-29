import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static boolean flag = false;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		String res = br.readLine();
		
		while(true){
			if(str.length() == res.length()){
				if(str.equals(res)){
					flag = true;
				}
				break;
			}
			char c = res.charAt(res.length()-1);
			res = res.replaceFirst(".$","");
			if ( c == 'B'){
				StringBuffer sb = new StringBuffer(res);
				System.out.println(res);
				res = sb.reverse().toString();
				System.out.println(res);
			}
			
		}
		if (flag) System.out.println(1);
		else System.out.println(0);
		
	}
	
}
