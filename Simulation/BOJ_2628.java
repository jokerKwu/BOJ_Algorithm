import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
/*
 10 8
 3
 0 3
 1 4
 0 2
 */
class Pair{
	int x,y;
	public Pair(int x,int y){
		this.x = x;
		this.y = y;
	}
}
public class Main {
	static int N;
	static int mx,my;
	static boolean[][] visit;
	static boolean[][] slice;
	static int[][] m_xy = {{0,1},{1,0},{0,-1},{-1,0} };
	static int MAX = 102;
	static int answer = 0;
	public static int bfs(int x,int y){
		int cnt = 1;
		Queue<Pair> que = new LinkedList<Pair>();
		que.add(new Pair(x,y));
		visit[y][x] = true;
		
		while(!que.isEmpty()){
			Pair cur_pos = que.poll();
			for(int i=0;i<4;i++){
				Pair next_pos = new Pair(cur_pos.x + m_xy[i][0] , cur_pos.y+m_xy[i][1]);
				if(next_pos.x<0 || next_pos.y<0 || next_pos.x>=mx || next_pos.y>=my) continue;
				if(!visit[next_pos.y][next_pos.x]){
					//가로 잘랐는지 체크하고 안잘랐으면 이동가능
					if(i % 2 == 0 && !slice[0][next_pos.y]){
						visit[next_pos.y][next_pos.x] = true;
						que.add(next_pos);
						cnt += 1;
					}
					else if(i%2 == 1 && !slice[1][next_pos.x]){
						visit[next_pos.y][next_pos.x] = true;
						que.add(next_pos);
						cnt += 1;
					}
				}
			}
		}
		return cnt;
	}
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		mx = Integer.parseInt(st.nextToken());
		my = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(br.readLine());
		System.out.println(N);
		visit = new boolean[mx + 2][my + 2];
		slice = new boolean[2][MAX];
		for(int i=0;i<N;i++){
			st = new StringTokenizer(br.readLine()," ");
			int type = Integer.parseInt(st.nextToken());
			int num = Integer.parseInt(st.nextToken());
			slice[type][num] = true;
		}
		
		for(int i=0;i<my;i++){
			for(int j=0;j<mx;j++){
				if(visit[i][j] == false){
					answer = Math.max(bfs(j,i), answer);
				}
			}
		}
		System.out.println(answer);
	}
}
