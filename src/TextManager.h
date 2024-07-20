#include <string>
#include <SDL2/SDL_ttf.h>
#include <map>



class TextManager
{
public:
    static TextManager* GetInstance() { return m_instance = (m_instance != nullptr) ? m_instance : new TextManager(); }
    

    void LoadFont(const char* font_file_path, TTF_Font* font, int size);
    void FontStyle(TTF_Font* font, int font_style);
    void ClearFont(TTF_Font* font);
    void CleanAllFonts();


private:
   TextManager(){}
   static TextManager* m_instance;
   std::map<const char*, TTF_Font*> m_FontMap;

};