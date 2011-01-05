title: Christmas Tree
category: 2
description: During the Christmas season UAT put a Christmas tree in the commons area which is where all of the computers are located, where it is visible throughout most of the schools ground floor. A group of students modified the Christmas tree to be accessible from the internet using a BASIC Stamp and a PINK. After the modification the Christmas tree was able to be turned on or off from the web.
---
A team of students that are collectively known as the 244'ers by the room number they hang out in came together and modified the Christmas Tree that [UAT][2] had placed in the commons area at UAT. We provided an online URL where people could go and turn the tree on and off or scroll the tree from top to bottom. This was featured in the [GEEK 411 magazine][7] that UAT puts out every so often. [Full GEEK 411 Issue for Spring 2007 [PDF]][8]. [Copy of article from issue [PDF]][6].

# Hardware

The hardware we used was simple. The tree was purchased and put up by [UAT][2]. This was a classic fake Christmas tree you would find at any major retailer during the Christmas season. This mean that it was built in layers, and each layer had it's own ring of lights, these were all daisy chained together using standard wall plugs. We went in and just put in extension cords for each of the different layers, so that now each layer instead of being daisy chained to the previous was now on its own separate extension cord.

[Professor Clarke][1] had a ready built box which contained standard solid state relays. This meant that we could safely using a micro controller switch on and off 120 volt AC power. This was built into one of the standard blue boxes also used in the construction for housing, with the only thing being exposed being six wall plugs on the front face, each of which could be individually turned on and off.

As a micro controller we used the [BASIC Stamp][3], mainly for its ease of programming, and the fact that we had assumed it would be adequate for the job. Along with that we used a [PINK][4] (Parallax Internet Netburner Kit) which gave us a small embedded web server. The PINK is able to communicate over a serial connection to report HTML form submittals, so that the BASIC Stamp could then act upon them by changing the tree state to the state picked from the form on the website.

In the end the following hardware was used:

 - [BASIC Stamp Controller][3]
 - [PINK (Parallax Internet Netburner Kit)][4]
 - [6 solid state relays][5]
 - Extension cords
 - One unsuspecting tree
 
## Simple Website

The PINK has a minimal amount of storage on-board which allows you to put small web pages on it. I ended up creating a quick and dirty small website that allowed the viewer to see what state the tree was currently in, and since we had two web cameras on campus, I embedded those on the web site as well so that the viewer would be able to see in real-time what their changes had done to the Christmas tree.

# Hack was Hacked

Since the website was set up with a small form that allowed the browser to POST to the web server, it was rather simple to automate the turning on and off of the Christmas tree. We had clever people that were sending us messages over the tree by turning it on and off in morse code patterns, as well as just trying to turn it on and off as fast as they were able to send data to it (which annoyed other users, c'est la vie!). The best hack was when someone flashed S.O.S. on the tree early in the morning when campus was still pretty empty. It was a simple hack, but the one that stood out the most to me!

# Aftermath

This was my very first project when I joined UAT, and it was done just to drum up interest for what hardware hacking is, and to get more people to join us in the 244 lab and work on interesting projects and to do something interesting for the campus as a whole on Christmas. Having place [Google Analytics][9] code on the web pages, we had a way to find out how many people visited the tree, the stats are as follows:
 
 - Average: 4.76 Pages/Visitor
 - Unique Visits: 4,323
 - Pageviews: 20,577
 
This does not include the amount of times people attempted to visit but the small embedded server was overloaded and unable to respond to the requests in time.

[1]: http://lostboy.net/ "Ryan Clarke"
[2]: http://uat.edu/ "University of Advancing Technology"
[3]: http://www.parallax.com/tabid/295/Default.aspx
[4]: http://www.parallax.com/Store/Accessories/Communication/tabid/161/ProductID/40/CategoryID/36/List/0/Level/a/Default.aspx?SortField=ProductName,ProductName
[5]: http://efx-tek.com/topics/crydom.html
[6]: /Project/pdf/christmastreehack.pdf "Article in GEEK 411 about the Christmas Tree hack"
[7]: http://www.uat.edu/academics/Geek_411.aspx
[8]: http://www.uat.edu/webmedia/pdf/uatmedia_12397.pdf
[9]: http://www.google.com/analytics/