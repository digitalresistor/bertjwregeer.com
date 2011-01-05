title: Near Space
category: 2
description: Professor Ryan Clarke had seen a presentation by L. Paul Verhage at Parallax about Near Space balloons. Ryan had always wanted to launch a near space balloon and created a special topics class  at UAT to do so. He selected 15 students to be part of the class, with the goal of getting a payload of 12 pounds up to at least 90,000 ft. It was a great success, our first balloon hit 92,999 ft. Our second balloon was successfully launched and retrieved!
---
Near Space was both a project and an official class  at UAT (SCI388: Special topics in science: Near Space). The class  consisted of 15 people that were picked by Ryan Clarke, and upon passing an entrance exam put into three different groups; engineering, science and logistics. The goal of the class  was to send a balloon to 90,000 ft and to successfully recover the payload once the balloon burst. Our first launch Connery-1 went off without any major issues, and we completed our goal. We reached 93,000 ft and recovered the payload along with the data it had captured.

# Teams

<a href="http://www.flickr.com/photos/xistence/4450261512/" title="CONNERY-1 Ground Picture"><img src="http://farm5.static.flickr.com/4024/4450261512_77151d01de.jpg" width="500" height="331" alt="CONNERY-1 Ground Pictures" /></a>

Steve Harper holding the payload seconds before it is let go.

## Engineering

The engineering teams primary focus was to create the payload box, along with the structural support to hold all of the equipment in place. The engineering team was also in charge of designing and building a way to fill the latex balloon, building the flight computer, and radio. The engineering team also had to write the procedures for the launch, and test the various parts of the systems to make sure that it would survive the return trip from near space.

## Science

The science teams primary focus was science experiments that were to be performed while ascending and descending. The science team is also in charge of interpreting any data that did come back down, and in general anything related to science.

## Logistics

The logistics teams primary focus was ordering parts, and making sure they arrived on time, they were also in charge of making sure we were following all federal regulations and following the letter of the law. This team was also in charge of finding the appropriate launch sites, and predicting where the near space payload would fall back to earth so that we may recover it.

# Launches

<a href="http://www.flickr.com/photos/xistence/4449485211/" title="CONNERY-1 Ground Pictures by X-Istence, on Flickr"><img src="http://farm3.static.flickr.com/2785/4449485211_c5fde8dac3.jpg" width="331" height="500" alt="CONNERY-1 Ground Pictures" /></a>

Slowly and carefully putting gas into the balloon.

## CONNERY-1

CONNERY-1 was the first near space balloon we launched, it had onboard a BASIC Stamp 2, GPS, Radio, a photo-camera, and a video camera. We launched at 0640 mountain standard time, and retrieved the payload a few hours later. We hit an altitude of 92,999 ft. It was a huge success, and we were extremely happy. The pictures the payload took were absolutely stunning, and awe inspiring. We tracked the balloon using the APRS network.

<a href="http://www.flickr.com/photos/xistence/4450250942/" title="CONNERY-1 Near Space Picture"><img src="http://farm5.static.flickr.com/4025/4450250942_f91b7a46b2.jpg" width="500" height="375" alt="CONNERY-1 Near Space Pictures" /></a>

More pictures in my [Flickr Near Space photo set for CONNERY-1][4]

## CONNERY-2

CONNERY-2 was a huge success, we launched our second balloon with some modifications, we decided to take more pictures more often, and we also modified the flight computer to log more GPS strings. We also launched right before sunset so we were able to capture many more awesome pictures. The balloon was once again tracked using radio signals sent to the national APRS frequency.

<a href="http://www.flickr.com/photos/xistence/4449500773/" title="CONNERY-2 Near Space Picture"><img src="http://farm5.static.flickr.com/4012/4449500773_d6fa4ab722.jpg" width="500" height="375" alt="CONNERY-2 Near Space Pictures" /></a>

More pictures in my [Flickr Near Space photo set for CONNERY-2][5]

# Data logging and parsing

The Near Space payload consisted of a data logger that was logging data to an SD card a format that we well defined. When the data came back down to earth we needed a way to parse the data so that we could graph it using Excel and or other tools. I wrote a simple parser that parses the different format versions that we already have by automatically detecting in what format the file is. It then parses the data and outputs a comma separated file (csv).

[View code][1] [Download code][2]

# Documentation

For the project we decided from the start that we needed a good place to store information that would be accessible by the outside world, as well as to anyone that wanted to provide their insight. We also wanted to provide a way for people to track our progress and to find out more information about the project. We set up a near [space wiki][3], which contains most of the information about the project. Unfortunately not everyone that was on the project has wiki knowledge so documentation is unfortunately lacking somewhat.

# Future

It is our hope as a team that UAT will continue to do near space balloon launches, gathering more pictures in the process, along with various science experiments. There is just something to being able to say that you were part of a team that helped launch a balloon to 93,000 ft.

[1]: http://nearspace.0x58.com/launches/Tools/ParseFCU.html
[2]: http://nearspace.0x58.com/launches/Tools/ParseFCU.cc
[3]: http://nearspace.0x58.com/
[4]: http://www.flickr.com/photos/xistence/sets/72157623536950565/
[5]: http://www.flickr.com/photos/xistence/sets/72157623537008243/