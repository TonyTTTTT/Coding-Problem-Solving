package org.uva.solver;

import java.lang.*;
import java.util.*;

public class Main {
    int block_num,a ,b;
    String cmd1, cmd2;
    Scanner sc = new Scanner(System.in);
    List<List> state = new ArrayList<>(block_num);
    int b_stk_idx, b_pos_idx;
    int a_stk_idx, a_pos_idx;

    private void init(int x) {
        this.state.get(x).clear();
        this.state.get(x).add(x);
    }

    private void findIndex() {
        this.b_stk_idx =-1;
        this.b_pos_idx =-1;
        for(int i=0; i<state.size(); i++) {
            if(state.get(i).indexOf(this.b) != -1) {
                this.b_stk_idx = i;
                this.b_pos_idx = state.get(i).indexOf(this.b);
//                System.out.printf("%d in stack %d pos %d\n", this.b, this.b_stk_idx, this.b_pos_idx);
                break;
            }
        }

        this.a_stk_idx =-1;
        this.a_pos_idx =-1;
        for(int i=0; i<state.size(); i++) {
            if(state.get(i).indexOf(this.a) != -1) {
                this.a_stk_idx = i;
                this.a_pos_idx = state.get(i).indexOf(this.a);
//                System.out.printf("%d in stack %d pos %d\n", this.a, this.a_stk_idx, this.a_pos_idx);
                break;
            }
        }

    }

    private void onto() {
        while(this.state.get(b_stk_idx).size() > this.b_pos_idx+1) {
            init(Integer.parseInt(this.state.get(this.b_stk_idx).get(this.b_pos_idx+1).toString()));
            this.state.get(this.b_stk_idx).remove(this.b_pos_idx+1);
        }
    }

    private void move() {
        while(this.state.get(a_stk_idx).size() > this.a_pos_idx+1) {
            init(Integer.parseInt(this.state.get(this.a_stk_idx).get(this.a_pos_idx+1).toString()));
            this.state.get(this.a_stk_idx).remove(this.a_pos_idx+1);
        }
        this.state.get(this.a_stk_idx).remove(this.a_pos_idx);
        this.state.get(this.b_stk_idx).add(this.a);
    }

    private void pile() {
        while(this.state.get(a_stk_idx).size() > this.a_pos_idx) {
            this.state.get(this.b_stk_idx).add(this.state.get(this.a_stk_idx).get(this.a_pos_idx));
            this.state.get(this.a_stk_idx).remove(this.a_pos_idx);
        }
    }

    private void  begin() {
        this.block_num = Integer.parseInt(this.sc.nextLine());
        for(int i=0; i<this.block_num; i++) {
            this.state.add(new ArrayList());
            this.state.get(i).add(i);
        }

        while(true) {
            this.cmd1 = this.sc.next();
            if("quit".equals(this.cmd1)) {
                break;
            }
            this.a = this.sc.nextInt();
            this.cmd2 = this.sc.next();
            this.b = this.sc.nextInt();
            findIndex();

            if(this.a == this.b || this.a_stk_idx == this.b_stk_idx)
                continue;
            if("move".equals(this.cmd1)) {
                if("onto".equals(this.cmd2)) {
//                    System.out.println("type 1");
                    onto();
                    move();
                }
                else {
//                    System.out.println("type 2");
                    move();
                }
            }
            else {
                if("onto".equals(cmd2)) {
//                    System.out.println("type3");
                    onto();
                    pile();
                }
                else {
//                    System.out.println("type4");
                    pile();
                }
            }
        }
    }

    public static void main(String[] args) {
        Main obj = new Main();
        obj.begin();
        for(int i=0; i<obj.state.size(); i++) {
            System.out.printf("%d:", i);
            for(int j=0; j<obj.state.get(i).size(); j++) {
                System.out.printf(" %d", obj.state.get(i).get(j));
            }
            System.out.printf("\n");
        }
    }
}