int main(){
    int n, m;
    int p[500010], q[500010];
    int room = 0;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        cin >> p[i];
        p[n+i] = p[i];
    }

    for(int i = 1 ; i < 2*n ; i++){ //prefix
        p[i] += p[i-1];
    }


    for(int i = 0 ; i < m ; i++){
        cin >> q[i];
    }

    for(int i = 0 ; i < m ; i++){
        if(room == 0){
            room = lower_bound(p, p+2*n, q[i]) - p + 1;
        }else{
            room = lower_bound(p+room, p+2*n, q[i] + p[room-1]) - p + 1;
        }
        room %= n;
    }

//    for(int i = 0 ; i < m ; i++){
//        int Q;
//        cin >> Q;
//        if(room == 0){
//            room = lower_bound(p, p+2*n, Q) - p + 1;
//        }else{
//            room = lower_bound(p+room, p+2*n, Q + p[room-1]) - p + 1;
//        }
//        room %= n;
//    }

    cout << room << endl;

    return 0;
}
