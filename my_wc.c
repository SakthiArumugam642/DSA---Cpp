#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void my_wc(int fd, int * w, int * l, int * c){
    int wc = 0, lc=0,cc=0;
    char ch, prev = '\0';
    int n;
    while((n = read(fd, &ch, 1)) > 0){
            cc++;
            if(ch == '\n'){ 
                lc++;
                if(prev != '\n' && prev != ' ') wc++;
            }
            
            if(ch == ' '){
                if(prev != ' ') wc++;
            }
            if(ch == '\t'){
                if(prev != '\t') wc++;
            } 
            prev = ch;
        }
    if((prev != '\t' && prev != ' ' && prev != '\n')){
        wc++;
    }
    *w += wc;
    *l += lc+1;
    *c += cc;
}

void print_values(int wc, int lc, int cc, char wf, char lf, char cf, char * filename){
    printf("\n");
    if(wf) printf("%d ", wc);
    if(lf) printf("%d ", lc);
    if(cf) printf("%d ", cc);
    if(strcmp(filename, "stdin") != 0) printf("%s", filename);
}

int main(int argc, char * argv[]){
    char wf, lf,cf,tf;
    int ret,fd;
    wf = lf = cf = tf = 0;
    int wc,lc,cc,tw,tl,tc;
    wc = lc = cc = tw = tl = tc = 0;

    while((ret = getopt(argc,argv,"wlc")) != -1){
        if(ret == 'w') wf = 1;
        if(ret == 'c') cf = 1;
        if(ret == 'l') lf = 1;
    }
    if(!wf && !lf && !cf){
    wf = lf = cf = 1;
    }
    if(argc - optind == 0){
        wf = lf = cf = 1;
        fd = 0;
        my_wc(fd, &wc, &lc, &cc);
        print_values(wc, lc, cc, wf, lf, cf, "stdin");
    }
    else{
        if(argc - optind > 1) tf = 1;
        for(int i = optind ; i < argc ; i++){
            fd = open(argv[i], O_RDONLY);
            if(fd == -1){
                perror("open");
                exit(1);
            }
            my_wc(fd, &wc, &lc, &cc);
            print_values(wc, lc, cc, wf, lf, cf, argv[i]);
            if(tf){
                tw += wc;
                tl += lc;
                tc += cc;
            }
            wc = lc = cc = 0;
            close(fd);
        }
        if(tf){
            print_values(tw, tl, tc, wf, lf, cf, "total");
        }
    }
    return 0;
}