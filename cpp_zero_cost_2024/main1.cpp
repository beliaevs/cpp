#include<vector>
#include<iostream>

//constexpr std::string kGreating = "Hey! It's our std::vector<bool> demo." 
//                                  " Check it out!";

const std::string kGreating = "Hey! It's our std::vector<bool> demo." 
                                  " Check it out!";
                                  
class Processor {
    public:
    Processor(std::size_t size): data_{std::vector<bool>(size)} {}
    bool CopyAndFlip(std::size_t ind) {
        const auto val = data_[ind];
        data_[ind] = !data_[ind];
        return val;
    }

    bool Get(std::size_t ind) const {
        return data_[ind];
    }

    private:
    //std::vector<bool> data_();
    std::vector<bool> data_{};
};

int main()
{
    std::cout << kGreating << std::endl;

    Processor p(10);
    std::cout << p.Get(1) << std::endl;
    std::cout << p.CopyAndFlip(1) << std::endl;
    std::cout << p.Get(1) << std::endl;

    return 0;
}

