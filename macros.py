base_url = "http://bertjwregeer.com/"

# It is 2011, time to add some of the social stuff we've heard so much about ...

social = [
	{'title': "Twitter",	'alt': "Twitter: @bertjwregeer",	'url': "http://twitter.com/bertjwregeer"},
	{'title': "Flickr",	'alt': "Flickr: xistence", 		'url': "http://www.flickr.com/photos/xistence/"},
	{'title': "Facebook",	'alt': "Facebook: xistence", 		'url': "http://facebook.com/xistence/"},
	{'title': "LinkedIn",	'alt': "LinkedIn: bertjwregeer", 	'url': "http://www.linkedin.com/in/bertjwregeer"},
	{'title': "Hacker News",'alt': "Hacker News: X-Istence",	'url': "http://news.ycombinator.com/user?id=X-Istence" },
	{'title': "BitBucket",	'alt': "Bitbucket: xistence",		'url': "http://code.bertjwregeer.com/" }
]

# Categories that exist
categories = {
	1: { 'title': "", 		'special': False },
	2: { 'title': "Projects", 	'special': False },
	3: { 'title': "Networking",		'special': True,	'items': social },
}

# Type of sorting for the category, True is use position variable, false uses title name.
sorting = {
	1: True,
	2: False,
	3: False,
}

page = {} # you can also set defaults here, see previous section
pages = []

def create_menu():
	cpages = {}
	for key in categories:
		if categories[key]['special'] is False:
			cpages[key] = [p for p in pages if "category" in p and int(p.category) == key]
		else:
			cpages[key] = categories[key]['items']
	
	for key in cpages:
		if sorting[key]:
			cpages[key].sort(key=lambda p: int(p.get("position", "100")))
		else:
			cpages[key].sort(key=lambda p: p.get("title") if p.get("sort") is None else p.get("sort"))
	
	htmlnav = "<ul>%s</ul>"
	items = ""
	
	for key in cpages:
		htmlcat = "<li><h1>%s</h1>\n<ul>%s\n</ul>\n</li>"
		
		clinktitle = categories[key]['title'];

		if categories[key].get("link") is not None:
			clinktitle = '<a href="%s" title="%s">%s</a>' % (categories[key]['link'], categories[key]['title'], categories[key]['title'])
		
		pitems = ""
		
		for p in cpages[key]:
			if p.get("nolink") is not None:
				continue
			
			htmlpage = '\t<li%s><a href="%s" title="%s">%s</a></li>'
			
			linktitle = p.get('ltitle') if p.get('ltitle') is not None else p.get('title')
			current = ' class="current"' if page.get('title') == p.get('title') else ''		
			alttext = p.get('alt') if p.get('alt') is not None else p.get('title')
						
			html = htmlpage % (current, p.get('url'), alttext, linktitle)
			
			pitems = "%s\n%s" % (pitems, html)
		
		html = htmlcat % (clinktitle, pitems)
		
		items = "%s\n%s" % (items, html)
	
	return htmlnav % (items)
	


# -----------------------------------------------------------------------------
# generate sitemap.xml
# -----------------------------------------------------------------------------

from datetime import datetime
import os.path

_SITEMAP = """<?xml version="1.0" encoding="UTF-8"?>
<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9">
%s
</urlset>
"""

_SITEMAP_URL = """
<url>
	<loc>%s/%s</loc>
	<lastmod>%s</lastmod>
	<changefreq>%s</changefreq>
	<priority>%s</priority>
</url>
"""

def once_sitemap():
	"""Generate Google sitemap.xml file."""
	date = datetime.strftime(datetime.now(), "%Y-%m-%d")
	urls = []
	for p in pages:
		urls.append(_SITEMAP_URL % (base_url.rstrip('/'), p.url, date, 
					    p.get("changefreq", "monthly"), p.get("priority", "0.8")))
	fname = os.path.join(options.project, "output", "sitemap.xml")
	fp = open(fname, 'w')
	fp.write(_SITEMAP % "".join(urls))
	fp.close()
