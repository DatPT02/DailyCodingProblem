#include "FileSystem.cpp"


int main()
{
    std::cout<<"Daily Coding Problem 17"<<std::endl;

    std::string fileStructure = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    //std::string fileStructure = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    FileSystem* myFileSystem = new FileSystem(fileStructure);
    myFileSystem->printStructure();
    std::cout<<std::endl<<"Longest: "<<myFileSystem->getLongestPath()<<" | length "<<myFileSystem->getLongestPath().length()<<std::endl;

    return 0;
}