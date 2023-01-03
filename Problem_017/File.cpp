#include <iostream>
#include <vector>
#include <algorithm>

class File
{
private:
    std::string name;
    std::string path;
    bool is_directory;
    File* parent;
    std::vector<File*> childs;
public:
    File(std::string name) : name(name), path(name), parent(nullptr), 
                            is_directory(name.find(".") == std::string::npos) {};

    void setParent(File& parent)
    {
        if(!parent.is_directory)
        {
            return;
        }
        this->parent = &parent;
        parent.addChild(this);

        updatePath();
    }

    File* getParent()
    {
        return this->parent;
    }

    void addChild(File *child)
    {
        if(std::find(this->childs.begin(), this->childs.end(), child) != this->childs.end())
            return;

        if(child->getParent() == nullptr || this->path != child->getParent()->path)
        {
            child->setParent(*this);
            this->childs.push_back(child);
        }
    }

    void updatePath()
    {
        if(this->getParent() == nullptr)
            this->path = this->name;
        else    
            this->path = this->parent->getPath() + "/" + this->name;

        for(File *file : this->childs)
        {
            file->updatePath();
        }
    }

    std::vector<File*> getChilds() const
    {
        return this->childs;
    }

    std::string getPath() const
    {
        return this->path;
    }

    std::string getName() const
    {
        return this->name;
    }

    bool isDirectory() const
    {
        return is_directory;
    }

    int getFileLevel()
    {
        int level = std::count(this->path.begin(), this->path.end(), '/');

        return level;
    }

    friend bool operator ==(const File& file1,const File& file2);
};

bool operator ==(const File& file1,const File& file2)
{
    return file1.getPath() == file2.getPath() && file1.isDirectory() == file2.isDirectory();
}