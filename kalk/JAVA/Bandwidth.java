public class Bandwidth{

    private int ping;
    private float download; //Mbps
    private float upload; //Mbps
    
    Bandwidth(int p, float d, float u){
        if(p < 0)
            ping = 0;
        else
            ping = p;

        if(d < 0)
            download = 0;
        else
            download = d;

        if(u < 0)
            upload = 0;
        else
            upload = u;
    }//constructor
    
    Bandwidth( Bandwidth x){
        this(x.ping, x.download, x.upload);
    }//copy constructor
    
    Bandwidth(){
        this(0, 0 ,0);
    }

    //operations
    
    Bandwidth sum( Bandwidth x){
        return new Bandwidth(ping + x.ping, download + x.download, upload + x.upload);
    }//sum
    
    Bandwidth substract( Bandwidth x){
        return new Bandwidth(ping - x.ping, download - x.download, upload - x.upload);
    }//substract
    
    Bandwidth multiplication(int x){
        return new Bandwidth(ping * x, download * x, upload * x);
    }
    
    Bandwidth division(int x ){
        if(x == 0){
        System.out.println( "Divisione per 0!!!");
        return new Bandwidth();
        }
        return new Bandwidth(ping / x, download / x, upload / x);
    }//division
    
    Bandwidth mod(int x){
        if(x == 0){
        System.out.println( "Divisione per 0!!!");
        return new Bandwidth();
        }
        return new Bandwidth(ping % x, (int)download % x, (int)upload % x);
    }//mod%
    
    boolean greaterThan( Bandwidth x){ //TRUE se piu velcoe
        double  temp1, temp2;
        temp1 = upload + download;
        temp2 = x.upload + x.download;

        if(temp1 == temp2)
            return ping < x.ping;
        
        return temp1 > temp2;
    }//greaterThan

    boolean lessThan( Bandwidth x){ // TRUE se piu lenta
        double  temp1, temp2;
        temp1 = upload + download;
        temp2 = x.upload + x.download;

        if(temp1 == temp2)
            return ping > x.ping;
        
        return temp1 < temp2;
    }//lessThan
    
    boolean equalTo( Bandwidth x){
        return ping == x.ping && download == x.download && upload == x.upload;
    }//equalTo

    void print(){
        System.out.println("Ping: " + this.ping);
        System.out.println("Download: " + this.download + " Mbps");
        System.out.println("Upload: " + this.upload + " Mbps");
        System.out.println();
    }
}
