const Seneca = require('seneca');

Seneca().quiet()
  .use('promisify')
  .use('entity')
  .use('provider', {
    provider: {
      hubspot: {
        keys: {
          accessToken: {
            value: 'pat-eu1-6eccc772-650a-4588-b617-27bbdd93187e'
          },
        }
      }
    }
  })
  .use('hubspot-provider')
  .ready(async function() {
    const seneca = this

    // console.log('SDK:', seneca.export('HubspotProvider/sdk')())

    console.log(await seneca.post('sys:provider,provider:hubspot,get:info'))
    
    const list = await seneca.entity("provider/hubspot/company").list$()
    console.log(list)
    const company = await seneca.entity("provider/hubspot/company").load$('5808044262/type/name/city/state/description'); // customize properties you want to get from a given company e.g. "id/name/domain/description"

    // editing description examples
    company.properties.description = `Found${company.properties.city}...`
    await company.save$();
    console.log('COMPANY DATA: ', company);
  });
