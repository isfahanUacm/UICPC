import java.util.Scanner;


public class hunt_jm {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
				
		int xsize = in.nextInt(), ysize = in.nextInt();
		char[][] map = new char[ysize][];
		int sx = 0, sy = 0;
		for (int y = 0; y < ysize; y++)
		{
			map[y] = in.next().toCharArray();
			for (int x = 0; x < xsize; x++)
			{
				if (map[y][x] == 'P')
				{
					sx = x;
					sy = y;
				}
			}
		}
		System.out.println(Go(map, sx, sy));
	}
	
	static int[] dx = new int[] { 0,1,0,-1}, dy = new int[] { 1,0,-1,0};

	private static int Go(char[][] map, int x, int y)
	{
		if (map[y][x] == '#') return 0;
		int sum = map[y][x] == 'G' ? 1 : 0;
		map[y][x] = '#';
		for (int i = 0; i < 4; i++)
			if (map[y + dy[i]][x + dx[i]] == 'T')
				return sum;
		for (int i = 0; i < 4; i++)
			sum += Go(map, x + dx[i], y + dy[i]);
		return sum;
	}
}
