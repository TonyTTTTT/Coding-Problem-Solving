import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;


public class Main {
    int[][] bins = new int[3][3];
    int bottleSum;
    String[] binPermutations = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    Scanner sc = new Scanner(System.in);

    private void parseLine(String line) {
        String[] tokens = line.split(" ");
        int tokenPos = 0;
        this.bottleSum = 0;
        for(int i=0; i<this.bins.length; i++) {
            this.bins[i][0] = Integer.parseInt(tokens[tokenPos]);
            this.bins[i][2] = Integer.parseInt(tokens[tokenPos+1]);
            this.bins[i][1] = Integer.parseInt(tokens[tokenPos+2]);
            tokenPos += 3;
            for(int j=0; j<this.bins[0].length; j++) {
                this.bottleSum += this.bins[i][j];
            }
        }
    }
    private void algo(){
        // int BN=0, GN=0, CN=0;
        // for(int i=0; i<bins.length; i++) {
        //     BN += bins[i][0];
        //     GN += bins[i][1];
        //     CN += bins[i][2];
        // }
        int[] permutations = new int[6];
        int pos = 0;
        for(int i=0; i<bins[0].length; i++) {
            for(int j=0; j<bins[0].length; j++) {
                if(j == i){continue;}
                for(int k=0; k<bins[0].length; k++) {
                    if(k == i || k == j){continue;}
                    permutations[pos] += bins[0][i] + bins[1][j] + bins[2][k];
                    pos ++;
                }
            }
        }
        for(int i=0; i<permutations.length; i++) {
            permutations[i] = this.bottleSum - permutations[i];
        }
        int ansIdx = 0;
        for(int i=1; i<permutations.length; i++) {
            if(permutations[i] < permutations[ansIdx]) {
                ansIdx = i;
            }
        }
        System.out.printf("%s %d\n", this.binPermutations[ansIdx], permutations[ansIdx]);
    }
    public void readFile(String fileName) {
        File dataFile = new File(fileName);
        try {
            BufferedReader reader = new BufferedReader(new FileReader(dataFile));
            try {
                for(String line = reader.readLine(); line != null; line = reader.readLine()) {
                    System.out.println(line);
                    this.parseLine(line);
                    this.algo();
                }
                reader.close();
            }
            catch(IOException ex) {
                System.out.println(ex);
            }
        }
        catch(FileNotFoundException ex) {
            System.out.println(ex);
        }
    }
    public void readInput() {
        while(sc.hasNextLine()) {
            String line = sc.nextLine();
            this.parseLine(line);
            this.algo();
        }
    }
    public static void main(String[] args) {
        Main main = new Main();
        // main.readFile(args[0]);
        main.readInput();
    }
}