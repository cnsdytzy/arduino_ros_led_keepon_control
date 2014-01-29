#! /usr/bin/env python
import argparse
import os

def get_arguments():
  parser = argparse.ArgumentParser(description="publish a scenario trigger.")
  parser.add_argument("scenario_type", type=int, help="0=None, 1=Turn, 2=Backup, 3=Brake, 4=Obstacle")
  parser.add_argument("scenario_arg", type=int, help="turn angle (for Turn), velocity (for Backup and Brake), obstacle angle (for Obstacle)")
  args = parser.parse_args()
  return args

def publish_topic(args):
  scenario = ""
  if(args.scenario_type == 0):
    scenario = "None"
  elif(args.scenario_type == 1):
    scenario = "Turn Corner"
  elif(args.scenario_type == 2):
    scenario = "Back Up"
  elif(args.scenario_type == 3):
    scenario = "Brake"
  elif(args.scenario_type == 4):
    scenario = "Obstacle"
  cmd = "rostopic pub -1 /qcbot_scenario_triggers led_keepon/ScenarioTrigger " + '"scenario: ' + "'" + scenario + "'\nparam: " + str(args.scenario_arg) + '"'
  print
  print cmd
  print "SCENARIO = %s" % scenario
  print "PARAM = %d" % args.scenario_arg
  os.system(cmd)
  print

if __name__=='__main__':
  args = get_arguments()
  publish_topic(args)