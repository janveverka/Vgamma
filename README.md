# Vgamma
CMSSW user code of Jan Veverka with packages for the CMS 2011 Vgamma
analysis of the 7 TeV data.

## History
These CMSSW packages were imported from the retired CVS
repository [1] on 5 March 2014.  Originally, they used to live at [2]
and were archived at [3].

They were imported using the HEAD version of cvs2git [4] using these commands:

    MY_GITHUB_USER=`git config --get user.github`
    MY_REMOTE=git@github.com:$MY_GITHUB_USER/Vgamma.git
    /tmp/veverka/git/cvs2svn/cvs2git --options=my-cvs2git.options
    git init Vgamma
    cd Vgamma
    git remote add origin $MY_REMOTE
    cat ../git-blob.dat ../git-dump.dat | git fast-import

See also [5].  The file with the cvs2git options is stored at [6].

- [1] /afs/cern.ch/project/cvs/reps/CMSSW/UserCode/JanVeverka/Vgamma
- [2] http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/UserCode/JanVeverka/Vgamma
- [3] http://cvs.web.cern.ch/cvs/cgi-bin/viewcvs.cgi/UserCode/JanVeverka/Vgamma
- [4] https://github.com/mhagger/cvs2svn/commit/b0ae0c98b0d5bf4b42425799814a9712d66c0073
- [5] http://cms-sw.github.io/cmssw/usercode-faq.html#how_do_i_migrate_to_github
- [6] https://github.com/janveverka/Vgamma/blob/master/my-cvs2git.options
