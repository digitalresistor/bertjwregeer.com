title: Projects
ltitle: More ...
alt: All of Bert's Projects
sort: zzzzzzzzzzzzzzz
category: 2
---
Not all of my projects are listed in the menu on the left, this is where you can get a little bit more information about all of my projects as well as access to the projects that are not listed.

# Projects

<!--%

# The category number, in this case number 2.
catnum = 2

# Get all pages in the category
pages = [p for p in pages if "category" in p and int(p.category) == catnum]

# Sort pages according to custom rules, if a sort order exists, sort by it, otherwise sort by title name
pages.sort(key=lambda p: p.get("title") if p.get("sort") is None else p.get("sort"))

output = '<ul class="projects">%s</ul>'

pitems = ""

for p in pages:
    if p.title == page.title:
        continue
        
    lioutput = '<li><a href="%s" alt="%s">%s</a><p>%s</p></li>'
    
    linktitle = p.ltitle if p.get("ltittle") is not None else p.title
    description = p.description if p.get("description") is not None else ''
    alttext = p.alt if p.get('alt') is not None else p.title
    
    html = lioutput % (p.url, alttext, linktitle, description)
    
    pitems = "%s\n%s" % (pitems, html)

out = output % (pitems)

print out
%-->

# More information

If you would like more information about any other projects that may not be listed here, or about any projects listed here please feel free to [contact me][1].

[1]: /Contact.html