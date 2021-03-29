import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
	static int N,K;
	static List<Integer> arr = new LinkedList<Integer>();
	static boolean check[];
	static int answer;
	static void backtracking(int total, int cnt){
		if(total < 500) return;
		if(cnt == N && total >= 500){
			answer += 1;
		}
		for(int i=0;i<N;i++){
			if(!check[i]){
				check[i] = true;
				backtracking(total + (arr.get(i) - K) , cnt + 1);
				check[i] = false;
			}
		}
		return;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		check = new boolean[N+1]; 
		st = new StringTokenizer(br.readLine()," ");
		while(st.hasMoreElements()){
			arr.add(Integer.parseInt(st.nextToken()));
		}
		
		backtracking(500, 0);
		System.out.println(answer);
		
	}
}
