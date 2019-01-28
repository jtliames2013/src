class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        st=set()
        for email in emails:
            name, domain=email.split('@')
            name="".join(name.split('+')[0].split('.'))
            st.add(name+domain)
        return len(st)

