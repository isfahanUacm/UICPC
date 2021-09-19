import java.util.*;

public class S2048 {

    public ListInteger filterNotZero(Integer ... values){
        return filterNotZero(new ArrayList(Arrays.asList(values)));
    }

    public ListInteger filterNotZero(ListInteger row){
        ArrayListInteger filtered = new ArrayList();
        for(int i=0;irow.size();i++){
            if(!row.get(i).equals(0))
                filtered.add(row.get(i));
        }
        return filtered;
    }

    public ListInteger merge(ListInteger row, Integer dir){
        if(row.size() == 4 && row.get(0).equals(row.get(1)) && row.get(2).equals(row.get(3))){
            ArrayListInteger merged = new ArrayList();
            merged.add(2  row.get(0));
            merged.add(2  row.get(2));
            return merged;
        }
        if(dir.equals(0)){
            for(int i=0; irow.size()-1; i++){
                if(row.get(i).equals(row.get(i+1))){
                    row.set(i, 2  row.get(i));
                    row.set(i+1, 0);
                    break;
                }
            }
        }
        else if(dir.equals(2)){
            for(int i=row.size()-1; i0; i--){
                if(row.get(i).equals(row.get(i-1))){
                    row.set(i, 2  row.get(i));
                    row.set(i-1, 0);
                    break;
                }
            }
        }
        return filterNotZero(row);
    }

    public static void main(String[] args) {
        S2048 solver = new S2048();
        Scanner scanner = new Scanner(System.in);
        Integer[][] grid = new Integer[4][4];
        for(int i=0;i4;i++)
            for(int j=0;j4;j++)
                grid[i][j] = scanner.nextInt();
        Integer direction = scanner.nextInt();
        if(direction.equals(0)){
            for(int it=0;it4;it++){
                ListInteger newRow = solver.merge(solver.filterNotZero(grid[it][0], grid[it][1], grid[it][2], grid[it][3]), 0);
                for(int i=0;i4;i++){
                    if(i  newRow.size())
                        grid[it][i] = newRow.get(i);
                    else
                        grid[it][i] = 0;
                }
            }
        }
        else if(direction.equals(1)){
            for(int it=0;it4;it++){
                ListInteger newRow = solver.merge(solver.filterNotZero(grid[0][it], grid[1][it], grid[2][it], grid[3][it]), 0);
                for(int i=0;i4;i++){
                    if(i  newRow.size())
                        grid[i][it] = newRow.get(i);
                    else
                        grid[i][it] = 0;
                }
            }
        }
        else if(direction.equals(2)){
            for(int it=0;it4;it++){
                ListInteger newRow = solver.merge(solver.filterNotZero(grid[it][0], grid[it][1], grid[it][2], grid[it][3]), 2);
                Collections.reverse(newRow);
                for(int i=0;i4;i++){
                    if(i  newRow.size())
                        grid[it][3-i] = newRow.get(i);
                    else
                        grid[it][3-i] = 0;
                }
            }
        }
        else if(direction.equals(3)){
            for(int it=0;it4;it++){
                ListInteger newRow = solver.merge(solver.filterNotZero(grid[0][it], grid[1][it], grid[2][it], grid[3][it]), 2);
                Collections.reverse(newRow);
                for(int i=0;i4;i++){
                    if(i  newRow.size())
                        grid[3-i][it] = newRow.get(i);
                    else
                        grid[3-i][it] = 0;
                }
            }
        }
        for(int i=0;i4;i++){
            for(int j=0;j4;j++)
                System.out.print(grid[i][j]+ );
            System.out.println();
        }

    }
}