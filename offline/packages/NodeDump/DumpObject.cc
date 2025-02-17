#include "DumpObject.h"

#include "PHNodeDump.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

DumpObject::DumpObject(const string &NodeName)
  : ThisName(NodeName)
{
  return;
}

int DumpObject::Init()
{
  if (ThisName != "DUMMY")
  {
    OpenOutFile();
  }
  return 0;
}

int DumpObject::OpenOutFile()
{
  if (no_output)
  {
    return 0;
  }
  string fname = OutDir + "/" + ThisName + ".list";
  fout = new ofstream(fname.c_str());
  return 0;
}

void DumpObject::Print(const char */*what*/) const
{
  cout << ThisName << " did not implement Print method" << endl;
  return;
}

int DumpObject::process_event(PHNode *myNode)
{
  if (fout && write_run_event)
  {
    if (fp_precision > 0)
    {
      (*fout).precision(fp_precision);
    }
    *fout << endl
          << "RunNumber: " << myNodeDump->RunNumber();
    if (print_evtseq)
    {
      *fout << ", Event Sequence: " << myNodeDump->EvtSequence();
    }
     *fout << endl;
  }
  process_Node(myNode);
  //  cout << ThisName << " did not implement process_event method" << endl;
  return 0;
}

int DumpObject::process_Node(PHNode */*myNode*/)
{
  //  cout << ThisName << " did not implement process_event method" << endl;
  return 0;
}

int DumpObject::CloseOutputFile()
{
  delete fout;
  fout = 0;
  return 0;
}
