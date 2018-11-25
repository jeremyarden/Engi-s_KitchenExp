InputUser();
    while (!(CKata.TabKata[1]=='E' && CKata.TabKata[2]=='X' && CKata.TabKata[3]=='I' && CKata.TabKata[4]=='T')) {
        if (CKata.Length==2) {
            if (CKata.TabKata[1]=='G') {
                if (CKata.TabKata[2]=='U') {
                    printf("1");
                }
                else if (CKata.TabKata[2]=='D') {
                    printf("2");
                }
                else if (CKata.TabKata[2]=='L') {
                    printf("3");
                }
                else if (CKata.TabKata[2]=='R') {
                    printf("4");
                }
                else {
                    printf("Masukan salah\n");
                    InputUser();
                }
            }
            else if (CKata.TabKata[1]=='C') {
                if (CKata.TabKata[2]=='H') {
                    printf("5");
                }
                else if (CKata.TabKata[2]=='T') {
                    printf("6");
                }
                else {
                    printf("Masukan salah\n");
                    InputUser();
                }
            }   
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==3) {
            if (CKata.TabKata[1]=='P' && CKata.TabKata[2]=='U' && CKata.TabKata[3]=='T') {
                printf("7");
            }
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==4) {
            if (CKata.TabKata[1]=='T' && CKata.TabKata[2]=='A' && CKata.TabKata[3]=='K' && CKata.TabKata[4]=='E') {
                printf("8");
            }
            else if (CKata.TabKata[1]=='G' && CKata.TabKata[2]=='I' && CKata.TabKata[3]=='V' && CKata.TabKata[4]=='E') {
                printf("9");
            }
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==5) {
            if (CKata.TabKata[1]=='P' && CKata.TabKata[2]=='L' && CKata.TabKata[3]=='A' && CKata.TabKata[4]=='C' && CKata.TabKata[5]=='E') {
                printf("10");
            }
            else if (CKata.TabKata[1]=='O' && CKata.TabKata[2]=='R' && CKata.TabKata[3]=='D' && CKata.TabKata[4]=='E' && CKata.TabKata[5]=='R') {
                printf("11");
            }
            else {
                printf("Masukan salah\n");
                InputUser();
            }
        }
        else if (CKata.Length==6) {
            if (CKata.TabKata[1]=='R' && CKata.TabKata[2]=='E' && CKata.TabKata[3]=='C' && CKata.TabKata[4]=='I' && CKata.TabKata[5]=='P' && CKata.TabKata[6]=='E') {
                printf("12");
            }
        }
        else {
            printf("Masukan salah\n");
            InputUser();
        }
        InputUser();
    }