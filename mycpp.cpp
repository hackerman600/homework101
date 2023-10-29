#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <Eigen/Dense>

#define ROWS 100
#define COLS 3

Eigen::MatrixXd generate_data(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> land_size(500,850);
    std::uniform_int_distribution<int> house_size(300,495);
    std::uniform_real_distribution<float> offset(1,1.3);
    
    Eigen::MatrixXd my_mate(ROWS,COLS);

    for (int r = 0; r < ROWS; r++){
        double land = (double)land_size(gen);
        double house = (double)house_size(gen);
        double off = offset(gen);
        double price = land * 1000 * off + house * 1000 * off; 
        
        for (int c = 0; c < COLS; c++){
            if (c == 0){
                my_mate(r,c) = land;
            }

            else if (c == 1){
                my_mate(r,c) = house;
            }
            
            else if (c == 2){
                my_mate(r,c) = price;
            }
        } 
    } 

    return my_mate;

}

void import_data(std::string file_path){

    std::ifstream myif(file_path);
    if (myif.is_open()){
        std::string str;
        while(getline(myif,str)){
            str = str + ",";
            std::cout << str;
            break;
            
        }

    }
       

}

void save_matrix(Eigen::MatrixXd my_mate){
    std::stringstream ss;
    ss << my_mate;
    std::string mystring = ss.str();
    std::cout << "mystring is: " << mystring;
    
    std::ofstream out("/home/kali/Downloads/mymate.txt");
    if (out.is_open()){
        out << mystring;
    } 
    else{
        std::cout << "file write operation failed";  
    }
}

int main(){

    //import_data();
    Eigen::MatrixXd my_mate = generate_data();
    
    //get the dimensions of the matrix.
    std::cout << "dimensions of the matrix are: (" << my_mate.rows() << ", " << my_mate.cols() << ")";

    //create x and y
    Eigen::MatrixXd x = my_mate.block(0,0,my_mate.rows(),2);
    Eigen::MatrixXd y = my_mate.col(2); 
    //std::cout << "x is: " << x << std::endl;
    //std::cout << "y is: " << y << std::endl;

    Eigen::MatrixXd myxl = x.array() * x.array();
    
    //save answer locally
    save_matrix(myxl);

    //check if the matrix saved
    std::ifstream ifs("/home/kali/Downloads/mymate.txt");
    if (ifs.is_open()){
        std::string mystr;
        while(getline(ifs,mystr)){
            std::cout << mystr;
            mystr = "";
        }
    }


    return 0;
}
