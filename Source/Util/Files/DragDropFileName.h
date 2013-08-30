#ifndef DRAGDROPFILEFRAME_H
#define	DRAGDROPFILEFRAME_H
/* 
 * @(#) DragDropFileFrame.h
 */
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif

#include <wx/arrstr.h>
#include <wx/dir.h>
#include <wx/busyinfo.h>

/* 
 * File:   DragDropFileFrame.h
 * 
 *              @class DragDropFileFrame
 *      
 *      @brief
 * 
 * @author James B. Silva <jbsilva@bu.edu> 
 * 
 * Created on December 28, 2012, 2:35 AM
 * 
 * * $Header $
 */
using namespace std;

class DragDropFileFrame : public wxFrame{
        public:    
        
            DragDropFileFrame();
            string getLastDroppedFile();
            
        private:
            string lastDroppedFile;
            bool fileDropped;
            void OnDropFiles(wxDropFilesEvent&);
         

};



#endif	/* DRAGDROPFILEFRAME_H */

