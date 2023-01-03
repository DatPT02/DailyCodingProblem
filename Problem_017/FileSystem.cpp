#include "File.cpp"

std::vector<std::string> split_string(std::string string, char delimeter)
{
    std::vector<std::string> output_string;
    size_t next = 0;
    size_t last = 0;

    while((next = string.find(delimeter,last)) != std::string::npos)
    {
        output_string.push_back(string.substr(last, next-last));
        last = next + 1;
    }

    output_string.push_back(string.substr(last));

    return output_string;
}

class FileSystem
{
private:
    File* root;
    std::vector<File> files;
public:
    FileSystem() {};

    FileSystem(File* root)
    {
        this->root = root;
        files.push_back(*root);
    }
    
    FileSystem(std::string fileStructure)
    {
        char newfile_delimeter = '\n';
        char subfile_delimeter = '\t';

        std::vector<std::string> substrs = split_string(fileStructure, newfile_delimeter);

        
        File* currentFile;
        int currentLevel = 0;

        for(auto string : substrs)
        {
            int level = std::count(string.begin(), string.end(), subfile_delimeter);
            string.erase(remove(string.begin(), string.end(), subfile_delimeter), string.end());
            File* file = new File(string);
            if(level == 0)
            {
                this->root = file;
                currentFile = file;
            }
            else{

                if(level != currentLevel)
                {
                    if(level > currentLevel)
                    {
                        // currentFile.addChild(*file);
                        // currentFile = *file;
                        file->setParent(*currentFile);
                        currentFile = file;
                    }
                    else
                    {
                        currentFile = currentFile->getParent()->getParent();
                        file->setParent(*currentFile);
                        currentFile = file;
                    }

                    currentLevel = level;
                }
                else
                {
                    currentFile = currentFile->getParent();
                    file->setParent(*currentFile);
                    currentFile = file;
                }
            }

            files.push_back(*file);
        }

    }

    void addFile(File* file)
    {
        files.push_back(*file);
    }

    std::string getLongestPath()
    {
        std::string longest = "";
        for(auto file : files)
        {
            if(file.getPath().length() > longest.length())
                longest = file.getPath();
        }

        return longest;
    }

    void printStructure()
    {
        std::cout<<std::endl<<"Structure"<<std::endl;
        for(auto file : files)
        {
            for(int i = 0; i < file.getFileLevel(); i ++)
            {
                std::cout<<"\t";
            }
            std::cout<<file.getName()<<std::endl;
        }
    }
};