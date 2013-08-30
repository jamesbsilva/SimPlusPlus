// File and Version Information:   DragDropFileName.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>

#include "DragDropFileName.h"


DragDropFileFrame::DragDropFileFrame()
        : wxFrame(NULL, wxID_ANY, _("Drag And Drop File To Process Here"))
    {
        fileDropped = false;
        wxBoxSizer* pSizer = new wxBoxSizer(wxVERTICAL);

        wxTextCtrl* dropTarget = new wxTextCtrl(this, wxID_ANY, _("Drop files onto me!"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY);
        dropTarget->DragAcceptFiles(true);
        pSizer->Add(dropTarget, 1, wxEXPAND, 0);

        SetSizer(pSizer);
        Layout();
        Centre();

        dropTarget->Connect(wxEVT_DROP_FILES, wxDropFilesEventHandler(DragDropFileFrame::OnDropFiles), NULL, this);

    }   

    void DragDropFileFrame::OnDropFiles(wxDropFilesEvent& event){
        if (event.GetNumberOfFiles() > 0) {

            fileDropped = true;
            wxString* dropped = event.GetFiles();
            wxASSERT(dropped);

            wxBusyCursor busyCursor;
            wxWindowDisabler disabler;      
            wxBusyInfo busyInfo(_("Adding files, wait please..."));

            wxString name;
            wxArrayString files;

            for (int i = 0; i < event.GetNumberOfFiles(); i++) {
                name = dropped[i];
                if (wxFileExists(name))
                    files.push_back(name);
                else if (wxDirExists(name))
                    wxDir::GetAllFiles(name, &files);                                    
            }

            wxTextCtrl* textCtrl = dynamic_cast<wxTextCtrl*>(event.GetEventObject());
            wxASSERT(textCtrl);
            textCtrl->Clear();
            if(files.size() == 1){
                name = files[0]; 
                string fileName(name.mb_str());
                printf("FILE: %s \n",fileName.c_str());
                lastDroppedFile = fileName;
            }else{
                for (size_t i = 0; i < files.size(); i++) {
                    name = files[i];
                    *textCtrl << name << wxT('\n');
                    string fileName(name.mb_str());
                    printf("FILE: %s \n",fileName.c_str());
                    lastDroppedFile = fileName;
                }
            }
            
            
        }
    }

    
    string DragDropFileFrame::getLastDroppedFile(){
        return lastDroppedFile;
    }

/**** MyApp ****/
class DragDropApp : public wxApp{
public:   
    virtual bool OnInit();

};

bool DragDropApp::OnInit(){
    if (!wxApp::OnInit())
        return false;          

    DragDropFileFrame* frame = new DragDropFileFrame();
    frame->Show();

    return true;
}

IMPLEMENT_APP(DragDropApp)