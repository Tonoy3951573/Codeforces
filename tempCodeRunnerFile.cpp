 sort(all(a),[](auto a, auto b)-> bool {
        if(a.first != b.first){
            return a.first < b.first;
        }
        else{   
            return a.seccond < b.seccond;
        }
    });