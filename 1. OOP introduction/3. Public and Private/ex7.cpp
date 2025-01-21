#include <iostream>

class Notes {
    std::string title;
    std::string author;
    int pages;

public:

    void set_data(const std::string& title, const std::string& author, int pages)
    {
        this->title = title;
        this->author = author;
        this->pages = pages;
    }

    void set_data(const Notes& note)
    {
        title = note.title;
        author = note.author;
        pages = note.pages;
    }

    const std::string& get_title()
        { return title; }

    const std::string& get_author()
        { return author; }

    int get_pages()
        { return pages; }

};

int main() {
    Notes *ptr_note1 = new Notes,
            *ptr_note2 = new Notes;

    ptr_note1->set_data("Фантазия экспромт", "Ф. Шопен", 5);

    ptr_note2->set_data(*ptr_note1);    

    // __ASSERT_TESTS__

    delete ptr_note1;
    delete ptr_note2;

    return 0;
}