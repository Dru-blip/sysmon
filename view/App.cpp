#include "App.h"
#include "view/MainFrame.h"


namespace sysmon {
    bool App::OnInit(){
        MainFrame *frame=new MainFrame();
        frame->Show();
        return true;
    }
}
