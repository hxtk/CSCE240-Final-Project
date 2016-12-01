#include "simulation.h"
/****************************************************************
* Implementation for the 'Simulation' class.
*
* Author/copyright:  Duncan Buell
* Used/Modified: Group 7
* Date: 30 November 2016
*
**/

static const string kTag = "SIM: ";

/****************************************************************
* Constructor.
**/
Simulation::Simulation() {}

/****************************************************************
* Destructor.
**/
Simulation::~Simulation() {}

/****************************************************************
* Accessors and mutators.
**/

/****************************************************************
* General functions.
**/

/****************************************************************
 * Function 'ReadPrecincts'.
 *
 * This function takes in a scanner that contains the data
 * for the precincts and their corresponding number, and then
 * puts it into a map of precincts.
 *
 * Parameters:
 * Scanner& infile - A scanner passed by reference that contains
 *                   the data for the precincts.
 *
**/
void Simulation::ReadPrecincts(Scanner& infile) {
  while (infile.HasNext()) {
    OnePct new_pct;
    new_pct.ReadData(infile);
    pcts_[new_pct.GetPctNumber()] = new_pct;
  }  // while (infile.HasNext()) {
}  // void Simulation::ReadPrecincts(Scanner& infile) {

/****************************************************************
 * Function 'RunSimulation'.
 *
 * This function iterates through each precinct in the map and
 * simulates the voting time for the voters in the precinct,
 * making sure to exclude outliers.  The data is contained
 * in a string that is written to an output stream.
 *
 * Parameters:
 * Configuration& config - The configuration information passed
 *                         by reference.
 * MyRandom& random - A random number generator.
 * ofstream& out_stream - the output stream to write to.
 *
**/
void Simulation::RunSimulation(const Configuration& config, MyRandom& random,
                               ofstream& out_stream) {
  string outstring = "XX";
  int pct_count_this_batch = 0;
  for (auto iterPct = pcts_.begin(); iterPct != pcts_.end(); ++iterPct) {
    OnePct pct = iterPct->second;

    int expected_voters = pct.GetExpectedVoters();
    //This statement discards outliers in the data
    if ((expected_voters <= config.min_expected_to_simulate_) ||
        (expected_voters > config.max_expected_to_simulate_))
      continue;

    outstring = kTag + "RunSimulation for pct " + "\n";
    outstring += kTag + pct.ToString() + "\n";
    Utils::Output(outstring, out_stream, Utils::log_stream);

    ++pct_count_this_batch;
    pct.RunSimulationPct(config, random, out_stream);

    //    break; // we only run one pct right now
  }  // for(auto iterPct = pcts_.begin(); iterPct != pcts_.end(); ++iterPct)

  outstring = kTag + "PRECINCT COUNT THIS BATCH " +
              Utils::Format(pct_count_this_batch, 4) + "\n";
  //  Utils::Output(outstring, out_stream);
  Utils::Output(outstring, out_stream, Utils::log_stream);
  //  out_stream << outstring << endl;
  //  out_stream.flush();
  //  Utils::log_stream << outstring << endl;
  //  Utils::log_stream.flush();

}  // void Simulation::RunSimulation()

/****************************************************************
* Usual 'ToString'.
**/
string Simulation::ToString() {
  string s = "";

  for (auto iterPct = pcts_.begin(); iterPct != pcts_.end(); ++iterPct) {
    s += kTag + (iterPct->second).ToString() + "\n";
  }

  return s;
}  // string Simulation::ToString()
